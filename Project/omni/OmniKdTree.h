#ifndef OMNIKDTREE_H
#define OMNIKDTREE_H

#include <algorithm>
#include <KdTree.h>
#include <Index.h>
#include <fstream>
#include <queue>

template <class Dtype>
class OmniKdTree: public Index
{

    //PRIVATE
    private:
        KdTree<Dtype>* tree;
        size_t diskAccess;
        std::string path;
        Pivot* pivot;
        DistanceFunction<Instance>* df;
        Dataset* laesaMatrix;
        Dataset* datasetOriginal;

        //Private methods
        void resetDiskAccess();
        void setPath();
        bool checkIfFileExists(std::string path);
        void saveLeafNode(LeafNode<Dtype>* node);
        void saveAllLeafNodes();
        Dataset* readLeafNode(LeafNode<Dtype>* node);
        TupleResult calculateV1V2(Instance* sq_, Instance* inst);
        void insertPriorityQueueResult(TupleResult inst, std::priority_queue<TupleResult, std::vector<TupleResult>, CompareTupleResult> & pqResult, size_t k, double & radius);
        Instance* pivotCoordinates(Instance* inst);

    //PUBLIC
    public:
        //Constructors and destructors
        OmniKdTree();
        OmniKdTree(Dataset* dataset, DistanceFunction<Instance>* distanceFunction, Pivot* pivot, size_t numPerLeaf);
        OmniKdTree(std::string serializedPath, DistanceFunction<Instance>* distanceFunction);
        ~OmniKdTree();

        //Public methods
        std::string toString();
        void incrementDiskAccess();
        void knn(Dataset* train, Instance* query, size_t k, std::vector<PairResult> & ans);
        void saveToFile();
        void loadFromFile(std::string fileName);

        //Getters
        size_t getDiskAccess();
        size_t getDistanceCount();

        //Setters
        void setDistanceFunction(DistanceFunction<Instance>* distanceFunction);

};



template <class Dtype>
void OmniKdTree<Dtype>::resetDiskAccess()
{

    diskAccess = 0;

}



template <class Dtype>
void OmniKdTree<Dtype>::setPath()
{

    int check = -1;

    while(check == -1)
    {

        std::string directory = "../omni/omni_files/",
                name = selectFolderName(directory, "omni");

        path = directory + name + "/";

        check = mkdir(path.c_str(), 0777);

    }

}



template <class Dtype>
bool OmniKdTree<Dtype>::checkIfFileExists(std::string path)
{

    std::ifstream file;
    file.open(path);

    if(file)
    {

        return true;

    }
    else
    {

        return false;

    }

}



template <class Dtype>
void OmniKdTree<Dtype>::saveLeafNode(LeafNode<Dtype>* node)
{

    std::string fileName = path + "leafnode_" + std::to_string(node->getNodeID()) + ".dat";

    if(!checkIfFileExists(fileName))
    {

        u_int32_t size = node->getDataset()->getSerializedSize();
        u_char* data = new u_char[size + sizeof(u_int32_t)];

        memcpy(data, &size, sizeof(u_int32_t));
        memcpy(data + sizeof(u_int32_t), (u_char*)node->getDataset()->serialize(), size);

        node->setDataset(new Dataset());

        std::ofstream file(fileName, std::ios::out | std::ios::binary);

        file.write((char*)data, size + sizeof(u_int32_t));
        file.close();

        delete [] data;

    }

}



template <class Dtype>
void OmniKdTree<Dtype>::saveAllLeafNodes()
{

    std::queue<Node<Dtype>*> queueNode;
    queueNode.push(tree->getRoot());
    Node<Dtype>* curr = nullptr;

    while(!queueNode.empty())
    {

        curr = queueNode.front();
        queueNode.pop();

        if(curr->getLeft() != nullptr)
        {

            queueNode.push(curr->getLeft());

        }

        if(curr->getRight() != nullptr)
        {

            queueNode.push(curr->getRight());

        }

        if(curr->isLeafNode())
        {

            saveLeafNode((LeafNode<Dtype>*)curr);

        }

    }

}



template <class Dtype>
Dataset* OmniKdTree<Dtype>::readLeafNode(LeafNode<Dtype>* node)
{

    Dataset* dataset = new Dataset();
    std::string fileName = path + "leafnode_" + std::to_string(node->getNodeID()) + ".dat";

    if(checkIfFileExists(fileName))
    {

        std::ifstream file(fileName, std::ios::in | std::ios::binary);

        u_int32_t size;
        u_char* dataSize = new u_char[sizeof(u_int32_t)];

        file.read((char*)dataSize, sizeof(u_int32_t));

        memcpy(&size, dataSize, sizeof(u_int32_t));

        u_char* data = new u_char[size + sizeof(u_int32_t)];

        file.seekg(0);
        file.read((char*)data, size + sizeof(u_int32_t));

        dataset->unserialize((char*)data + sizeof(u_int32_t));

        file.close();

        delete [] data;
        delete [] dataSize;

    }
    else
    {

        throw std::invalid_argument("File does not exist");

    }

    return dataset;

}



template<class Dtype>
TupleResult OmniKdTree<Dtype>::calculateV1V2(Instance* sq_, Instance* inst)
{

    double ansV1 = df->getDistance(*datasetOriginal->getInstance(sq_->getOID()), *datasetOriginal->getInstance(inst->getOID()));
    double ansV2 = ansV1;
//    double ansV1 = std::numeric_limits<double>::max(), ansV2 = std::numeric_limits<double>::max(), inf = 0, sup = 0;

//    for(size_t x = 0; x < inst->size(); x++)
//    {

//        inf = std::abs(sq_->get(x) - laesaMatrix->getInstance(inst->getOID())->get(x));
//        sup = sq_->get(x) + laesaMatrix->getInstance(inst->getOID())->get(x);

//        if(inf < ansV1 && sup < ansV2)
//        {

//            ansV1 = inf;
//            ansV2 = sup;

//        }
//        else if(inf < ansV1)
//        {

//            ansV1 = inf;

//        }
//        else if(sup < ansV2)
//        {

//            ansV2 = sup;

//        }

//    }



    return TupleResult(inst->getOID(), ansV1, ansV2);

}



template<class Dtype>
void OmniKdTree<Dtype>::insertPriorityQueueResult(TupleResult inst, std::priority_queue<TupleResult, std::vector<TupleResult>, CompareTupleResult> & pqResult, size_t k, double & radius)
{

    if(pqResult.size() == k)
    {

        if(inst.value2 <= radius)
        {

            pqResult.push(inst);
            std::vector<TupleResult> vec = dequeueInOrder<TupleResult, CompareTupleResult>(pqResult);
            radius = vec[k-1].value2;
            vec.clear();

        }
        else
        {

            if(inst.value1 <= radius)
            {

                pqResult.push(inst);

            }

        }

    }
    else
    {

        pqResult.push(inst);

        if(pqResult.size() == k)
        {

            std::vector<TupleResult> vec = dequeueInOrder<TupleResult, CompareTupleResult>(pqResult);
            radius = vec[k-1].value2;
            vec.clear();

        }

    }

}



template<class Dtype>
Instance* OmniKdTree<Dtype>::pivotCoordinates(Instance* inst)
{

    Instance* ans = new Instance(0, pivot->getNumberOfPivots());

    for(size_t x = 0; x < pivot->getNumberOfPivots(); x++)
    {

        ans->set(x, df->getDistance(*inst, *pivot->getPivot(x)));

    }

    return ans;

}



template <class Dtype>
OmniKdTree<Dtype>::OmniKdTree()
{

    tree = new KdTree<Dtype>();
    diskAccess = 0;
    pivot = nullptr;
    df = nullptr;
    laesaMatrix = nullptr;
    setPath();

}



template <class Dtype>
OmniKdTree<Dtype>::OmniKdTree(Dataset* dataset, DistanceFunction<Instance>* distanceFunction, Pivot* pivot, size_t numPerLeaf)
{

    tree = new KdTree<Dtype>(dataset, distanceFunction, pivot, numPerLeaf);
    diskAccess = 0;
    this->pivot = tree->getPivot();
    df = tree->getDistanceFunction();
    laesaMatrix = tree->getLaesaMatrix();
    setPath();
    saveAllLeafNodes();

}



template <class Dtype>
OmniKdTree<Dtype>::OmniKdTree(std::string serializedPath, DistanceFunction<Instance>* distanceFunction)
{

    loadFromFile(serializedPath);
    df = distanceFunction;
    diskAccess = 0;
    path = serializedPath.substr(0, serializedPath.find_last_of("/") + 1);
    //setPath();
    //saveAllLeafNodes();

}



template <class Dtype>
OmniKdTree<Dtype>::~OmniKdTree()
{

    if(tree != nullptr)
    {

        delete tree;

    }

}



template <class Dtype>
std::string OmniKdTree<Dtype>::toString()
{

    return tree->toString();

}



template <class Dtype>
void OmniKdTree<Dtype>::incrementDiskAccess()
{

    diskAccess++;

}



template <class Dtype>
void OmniKdTree<Dtype>::knn(Dataset* train, Instance* query, size_t k, std::vector<PairResult> & ans)
{

//    resetDiskAccess();
//    tree->resetDistanceCount();
//    datasetOriginal = train;

//    DistanceBrowsing* distanceBrowsing = new DistanceBrowsing(df);
//    std::priority_queue<Partition<Dtype>, std::vector<Partition<Dtype>>, ComparePartition<Dtype>> pqPartition;
//    std::priority_queue<TupleResult, std::vector<TupleResult>, CompareTupleResult> pqResult;
//    Instance* sq_ = pivotCoordinates(query);
//    sq_->setOID(query->getOID()); //OBS
//    double radius = std::numeric_limits<double>::max();
//    pqPartition.push(Partition<Dtype>(tree->getRoot(), 0.0, 0.0));

//    while(!pqPartition.empty() || )
//    {

//        Node<Dtype>* node = pqPartition.top().node;
//        pqPartition.pop();

//        if(node->isDirectoryNode())
//        {

//            double minL = distanceBrowsing->minDist(sq_, node->getLeft()->getBoundary());
//            double maxL = distanceBrowsing->maxDist(sq_, node->getLeft()->getBoundary());
//            double minR = distanceBrowsing->minDist(sq_, node->getRight()->getBoundary());
//            double maxR = distanceBrowsing->maxDist(sq_, node->getRight()->getBoundary());

//            pqPartition.push(Partition<Dtype>(node->getLeft(), minL, maxL));
//            pqPartition.push(Partition<Dtype>(node->getRight(), minR, maxR));

//        }
//        else
//        {

//            Dataset* dataLeafNode = readLeafNode((LeafNode<Dtype>*)node);
//            incrementDiskAccess();

//            std::cout << "ID LEAF NODE = " << node->getNodeID() << std::endl;

//            for(size_t x = 0; x < dataLeafNode->getCardinality(); x++)
//            {

//                insertPriorityQueueResult(calculateV1V2(sq_, dataLeafNode->getInstance(x)), pqResult, k, radius);

//            }

//            delete dataLeafNode;

//        }

//    }

//    std::vector<TupleResult> orderByV1 = dequeueInOrder<TupleResult, CompareTupleResult>(pqResult);

//    std::sort(orderByV1.begin(), orderByV1.end(), [](TupleResult const& a, TupleResult const& b){

//        return a.value1 > b.value1;

//    });

//    std::priority_queue<PairResult, std::vector<PairResult>, ComparePairResult> pqAns;

//    size_t i = 0;

//    while(i != orderByV1.size())
//    {

//        TupleResult pop = orderByV1[i];

//        if(pop.value1 <= radius)
//        {

//            double dist = df->getDistance(*query, *train->getInstance(pop.index));

//            if(dist <= radius)
//            {

//                if(pqAns.size() == k)
//                {

//                    pqAns.push(PairResult(train->getInstance(pop.index)->getOID(), dist));
//                    std::vector<PairResult> aux = dequeueInOrder<PairResult, ComparePairResult>(pqAns);
//                    radius = aux[k-1].distance;

//                    pqAns = std::priority_queue<PairResult, std::vector<PairResult>, ComparePairResult>();

//                    for(size_t x = 0; x < k; x++)
//                    {

//                        pqAns.push(aux[x]);

//                    }

//                }
//                else
//                {

//                    pqAns.push(PairResult(train->getInstance(pop.index)->getOID(), dist));

//                    if(pqAns.size() == k)
//                    {

//                        std::vector<PairResult> aux = dequeueInOrder<PairResult, ComparePairResult>(pqAns);
//                        radius = aux[k-1].distance;

//                        pqAns = std::priority_queue<PairResult, std::vector<PairResult>, ComparePairResult>();

//                        for(size_t x = 0; x < k; x++)
//                        {

//                            pqAns.push(aux[x]);

//                        }

//                    }

//                }

//            }

//        }

//        i++;

//    }

//    ans = dequeueInOrder<PairResult, ComparePairResult>(pqAns);
//    ans.resize(k);


//    orderByV1.clear();

//    while(!pqResult.empty())
//    {

//        pqResult.pop();

//    }

    resetDiskAccess();
    tree->resetDistanceCount();

    DistanceBrowsing* distanceBrowsing = new DistanceBrowsing(df);
    std::priority_queue<Partition<Dtype>, std::vector<Partition<Dtype>>, ComparePartition<Dtype>> pqPartition;
    std::priority_queue<PairResult, std::vector<PairResult>, ComparePairResult> pqCandidates;
    std::priority_queue<PairResult, std::vector<PairResult>, ComparePairResult2> pqAns;
    Instance* sq_ = pivotCoordinates(query);
    pqPartition.push(Partition<Dtype>(tree->getRoot(), 0.0, 0.0));
    Node<Dtype>* node = nullptr;
    Partition<Dtype> partition;

    std::cout << sq_->toString() << "\n\n";

    int i = 0;

    while(!pqPartition.empty() || pqCandidates.size() > 0)
    {

        std::cout << "\n\n-------------------ITERACAO WHILE " << i << "\n\n";

        std::cout << "PARTITION MIN = " << pqPartition.top().min << std::endl;
        std::cout << "DIST (query, pqCandidates.top) = " << (pqCandidates.empty() ? -1 : df->getDistance(*query, *train->getInstance(pqCandidates.top().index))) << std::endl;

        if(pqCandidates.size() == 0)
        {

            partition = pqPartition.top();
            node = partition.node;
            pqPartition.pop();

            std::cout << "POP NODE ID = " << node->getNodeID() << "\n\n";

            if(node->isLeafNode())
            {

                Dataset* dataLeafNode = readLeafNode((LeafNode<Dtype>*)node);
                incrementDiskAccess();

                std::cout << "ID LEAF NODE = " << node->getNodeID() << std::endl;

                for(size_t x = 0; x < dataLeafNode->getCardinality(); x++)
                {

                    std::cout << dataLeafNode->getInstance(x)->getOID() << " / " << df->getDistance(*query, *train->getInstance(dataLeafNode->getInstance(x)->getOID())) << std::endl;
                    pqCandidates.push(PairResult(dataLeafNode->getInstance(x)->getOID(), df->getDistance(*query, *train->getInstance(dataLeafNode->getInstance(x)->getOID()))));

                }

                delete dataLeafNode;

            }
            else
            {

                std::cout << "\nDIST BR = " << node->getLeft()->getNodeID() << " / " << node->getLeft()->showBounds() << std::endl;
                double minL = distanceBrowsing->minDist(sq_, node->getLeft()->getBoundary());
                double maxL = distanceBrowsing->maxDist(sq_, node->getLeft()->getBoundary());
                std::cout << "DIST BR = " << node->getRight()->getNodeID() << " / " << node->getRight()->showBounds() << std::endl;
                double minR = distanceBrowsing->minDist(sq_, node->getRight()->getBoundary());
                double maxR = distanceBrowsing->maxDist(sq_, node->getRight()->getBoundary());

                std::cout << "DIR = " << node->getLeft()->getNodeID() << " / " << minL << " / " << maxL << std::endl;
                std::cout << "DIR = " << node->getRight()->getNodeID() << " / " << minR << " / " << maxR << std::endl;
                pqPartition.push(Partition<Dtype>(node->getLeft(), minL, maxL));
                pqPartition.push(Partition<Dtype>(node->getRight(), minR, maxR));

            }

        }
        else if((pqPartition.size() > 0) && pqPartition.top().min < df->getDistance(*query, *train->getInstance(pqCandidates.top().index)))
        {

            node = pqPartition.top().node;
            pqPartition.pop();

            std::cout << "POP NODE ID = " << node->getNodeID() << std::endl;

            if(node->isLeafNode())
            {

                Dataset* dataLeafNode = readLeafNode((LeafNode<Dtype>*)node);
                incrementDiskAccess();

                std::cout << "ID LEAF NODE = " << node->getNodeID() << std::endl;

                for(size_t x = 0; x < dataLeafNode->getCardinality(); x++)
                {

                    std::cout << dataLeafNode->getInstance(x)->getOID() << " / " << df->getDistance(*query, *train->getInstance(dataLeafNode->getInstance(x)->getOID())) << std::endl;
                    pqCandidates.push(PairResult(dataLeafNode->getInstance(x)->getOID(), df->getDistance(*query, *train->getInstance(dataLeafNode->getInstance(x)->getOID()))));

                }

                delete dataLeafNode;

            }
            else
            {

                std::cout << "\nDIST BR = " << node->getLeft()->getNodeID() << " / " << node->getLeft()->showBounds() << std::endl;
                double minL = distanceBrowsing->minDist(sq_, node->getLeft()->getBoundary());
                double maxL = distanceBrowsing->maxDist(sq_, node->getLeft()->getBoundary());
                std::cout << "DIST BR = " << node->getRight()->getNodeID() << " / " << node->getRight()->showBounds() << std::endl;
                double minR = distanceBrowsing->minDist(sq_, node->getRight()->getBoundary());
                double maxR = distanceBrowsing->maxDist(sq_, node->getRight()->getBoundary());

                std::cout << "DIR = " << node->getLeft()->getNodeID() << " / " << minL << " / " << maxL << std::endl;
                std::cout << "DIR = " << node->getRight()->getNodeID() << " / " << minR << " / " << maxR << std::endl;
                pqPartition.push(Partition<Dtype>(node->getLeft(), minL, maxL));
                pqPartition.push(Partition<Dtype>(node->getRight(), minR, maxR));

            }

        }
        else
        {

            std::cout << "ADICIONA ELEMENTO NA RESPOSTA" << std::endl;
            if(!pqAns.empty() && !pqCandidates.empty() && pqAns.size() >= k && pqCandidates.top().distance > pqAns.top().distance)
            {

                std::cout << "DEVERIA TERMINAR AQUI";
                //break;

            }

            pqAns.push(pqCandidates.top());
            pqCandidates.pop();

            while(pqAns.size() > k)
            {

                pqAns.pop();

            }

        }

        std::cout << "\nPQ PARTITION = ";
        for(Partition<Dtype> pt : dequeueInOrder(pqPartition))
        {

            std::cout << pt.node->getNodeID() << ",";

        }

        std::cout << "\nPQ CANDIDATES = ";
        for(PairResult pt : dequeueInOrder(pqCandidates))
        {

            std::cout << pt.index << ",";

        }

        std::cout << "\nPQ ANS = ";
        for(PairResult pt : dequeueInOrder(pqAns))
        {

            std::cout << pt.index << ",";

        }


        i++;
    }

    ans = dequeueInOrder(pqAns);
    std::reverse(ans.begin(), ans.end());

    while(!pqCandidates.empty())
    {

        pqCandidates.pop();

    }

    while(!pqAns.empty())
    {

        pqAns.pop();

    }

    while(!pqPartition.empty())
    {

        pqPartition.pop();

    }

}



template <class Dtype>
void OmniKdTree<Dtype>::saveToFile()
{

    std::string nameAux = path.substr(path.rfind("/", path.size()-2)+1, path.find_last_of("/")),
            name = nameAux.substr(0, nameAux.size()-1),
            fileName = path + name + ".dat";

    std::ofstream file(fileName, std::ios::out | std::ios::binary);


    u_int32_t size = tree->getSerializedSize();
    u_char* data = new u_char[size + sizeof(u_int32_t)];

    memcpy(data, &size, sizeof(u_int32_t));
    memcpy(data + sizeof(u_int32_t), tree->serialize(), size);

    file.write((char*)data, size + sizeof(u_int32_t));
    file.close();

}



template <class Dtype>
void OmniKdTree<Dtype>::loadFromFile(std::string fileName)
{

    std::ifstream file(fileName, std::ios::in | std::ios::binary);

    u_char* seri = new u_char[sizeof(u_int32_t)];
    u_int32_t size;

    file.read((char*)seri, sizeof(u_int32_t));

    memcpy(&size, seri, sizeof(u_int32_t));

    u_char* data = new u_char[size + sizeof(u_int32_t)];

    file.seekg(0);
    file.read((char*)data, size + sizeof(u_int32_t));

    tree = new KdTree<Dtype>();
    tree->unserialize(data + sizeof(u_int32_t));

    pivot = tree->getPivot();
    df = tree->getDistanceFunction();
    laesaMatrix = tree->getLaesaMatrix();

}



template <class Dtype>
size_t OmniKdTree<Dtype>::getDiskAccess()
{

    return diskAccess;

}



template <class Dtype>
size_t OmniKdTree<Dtype>::getDistanceCount()
{

    return tree->getDistanceCount();

}



template <class Dtype>
void OmniKdTree<Dtype>::setDistanceFunction(DistanceFunction<Instance>* distanceFunction)
{

    tree->setDistanceFunction(distanceFunction);

}



#endif // OMNIKDTREE_H
