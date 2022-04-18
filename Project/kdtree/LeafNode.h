#ifndef LEAFNODE_H
#define LEAFNODE_H

#include "../utils/Dataset.h"
#include "../kdtree/Node.h"
#include <sstream>



template<class Dtype>
class LeafNode : public Node<Dtype>
{

    //Private
    private:
        Dataset* dataset;
        size_t s_dataset_cardinality, s_dataset_dimensionality, s_dataset_seed, s_bounds_size;

        //Getters
        size_t getDatasetCardinality();
        size_t getDatasetDimensionality();
        size_t getDatasetSeed();
        size_t getBoundsSize();

        //Setters
        void setSerializeVariables(size_t _s_dataset_cardinality, size_t _s_dataset_dimensionality, size_t _s_dataset_seed, size_t _s_bounds_size);


    //Public
    public:

        //Constructors and destructors
        LeafNode();
        LeafNode(Dataset* _dataset);
        LeafNode(Dataset* _dataset, Node<Dtype>* _parent, std::vector<DynamicArray<Dtype>> _bounds);
        ~LeafNode();

       //Getters
        Dataset* getDataset();
        Instance* getInstance(size_t pos);

       //Setters
        void setDataset(Dataset* _dataset);

       //Virtual
        bool isDirectoryNode();
        bool isLeafNode();
        bool equals(Node<Dtype>* other);
        std::string toString();
        u_int32_t getSerializeSize();
        u_char* serialize();
        void unserialize(u_char* data);

};



template<class Dtype>
size_t LeafNode<Dtype>::getDatasetCardinality()
{

    return s_dataset_cardinality;

}



template<class Dtype>
size_t LeafNode<Dtype>::getDatasetDimensionality()
{

    return s_dataset_dimensionality;

}



template<class Dtype>
size_t LeafNode<Dtype>::getDatasetSeed()
{

    return s_dataset_seed;

}



template<class Dtype>
size_t LeafNode<Dtype>::getBoundsSize()
{

    return s_bounds_size;

}



template<class Dtype>
void LeafNode<Dtype>::setSerializeVariables(size_t _s_dataset_cardinality, size_t _s_dataset_dimensionality, size_t _s_dataset_seed, size_t _s_bounds_size)
{

    s_dataset_cardinality = _s_dataset_cardinality;
    s_dataset_dimensionality = _s_dataset_dimensionality;
    s_dataset_seed = _s_dataset_seed;
    s_bounds_size = _s_bounds_size;

}



template<class Dtype>
LeafNode<Dtype>::LeafNode()
{

    this->setLeftNode(nullptr);
    this->setRightNode(nullptr);
    this->setParentNode(nullptr);
    this->setBoundary(std::vector<DynamicArray<Dtype>>());
    this->setNodeID(0);
    setDataset(nullptr);

}



template<class Dtype>
LeafNode<Dtype>::LeafNode(Dataset* _dataset)
{

    this->setLeftNode(nullptr);
    this->setRightNode(nullptr);
    this->setParentNode(nullptr);
    this->setBoundary(std::vector<DynamicArray<Dtype>>());
    this->setNodeID(0);
    setDataset(_dataset);

}



template<class Dtype>
LeafNode<Dtype>::LeafNode(Dataset* _dataset, Node<Dtype>* _parent, std::vector<DynamicArray<Dtype>> _bounds)
{

    this->setLeftNode(nullptr);
    this->setRightNode(nullptr);
    this->setParentNode(_parent);
    this->setBoundary(_bounds);
    this->setNodeID(0);
    setDataset(_dataset);

}



template<class Dtype>
LeafNode<Dtype>::~LeafNode()
{

    if(dataset != nullptr)
    {

        delete dataset;

    }

    if(this->getBoundary().size() > 0)
    {

        this->getBoundary().clear();

    }


}



template<class Dtype>
Dataset* LeafNode<Dtype>::getDataset()
{

    return dataset;

}



template<class Dtype>
Instance* LeafNode<Dtype>::getInstance(size_t pos)
{

    return dataset->getInstance(pos);

}



template<class Dtype>
void LeafNode<Dtype>::setDataset(Dataset* _dataset)
{

    dataset = _dataset;

}



template<class Dtype>
bool LeafNode<Dtype>::isDirectoryNode()
{

    return false;

}



template<class Dtype>
bool LeafNode<Dtype>::isLeafNode()
{

    return true;

}



template<class Dtype>
bool LeafNode<Dtype>::equals(Node<Dtype>* other)
{

    bool ans = true;

    if(other->isDirectoryNode())
    {

        ans = false;

    }
    else
    {

        ans = this->equalBounds(other->getBoundary());

    }

    return ans;

}



template<class Dtype>
std::string LeafNode<Dtype>::toString()
{

    std::stringstream st;
    st << "Node ID = " << this->getNodeID() << "\n";
    st << "Bounds : " << this->showBounds() << "\n";
    st << "Dataset : \n";

    for(size_t x = 0; x < getDataset()->getCardinality(); x++)
    {

        Instance* inst = getDataset()->getInstance(x);
        st << inst->getOID() << " -> ";

        for(size_t y = 0; y < getDataset()->getDimensionality(); y++)
        {

            st << inst->get(y) << " ";

        }

        st << "\n";

    }

    return st.str();

}



template<class Dtype>
u_int32_t LeafNode<Dtype>::getSerializeSize()
{

    setSerializeVariables(getDataset()->getCardinality(), getDataset()->getDimensionality(), getDataset()->getSeed(), this->getBoundary().size());
    u_int32_t datasetSize = (sizeof(u_int32_t) + sizeof(double) * (u_int32_t)getDatasetDimensionality()) * (u_int32_t)getDatasetCardinality();
    u_int32_t boundsSize = (u_int32_t)getBoundsSize() * (sizeof(Dtype) * 2);
    return datasetSize + boundsSize + sizeof(u_int32_t) * 5;

}



template<class Dtype>
u_char* LeafNode<Dtype>::serialize()
{

    u_char* data = nullptr;

    if(data == nullptr)
    {

        data = new u_char[getSerializeSize()];

        u_int32_t nodeID = (u_int32_t)this->getNodeID(), datasetCardinality = (u_int32_t)getDatasetCardinality(), datasetDimensionality = (u_int32_t)getDatasetDimensionality(), datasetSeed = (u_int32_t)getDatasetSeed(), boundsSize = (u_int32_t)getBoundsSize(), total = 0;

        memcpy(data + total, &nodeID, sizeof(u_int32_t));
        total += sizeof(u_int32_t);
        memcpy(data + total, &datasetCardinality, sizeof(u_int32_t));
        total += sizeof(u_int32_t);
        memcpy(data + total, &datasetDimensionality, sizeof(u_int32_t));
        total += sizeof(u_int32_t);
        memcpy(data + total, &datasetSeed, sizeof(u_int32_t));
        total += sizeof(u_int32_t);
        memcpy(data + total, &boundsSize, sizeof(u_int32_t));
        total += sizeof(u_int32_t);

        for(size_t x = 0; x < getBoundsSize(); x++)
        {

            memcpy(data + total, &this->getBoundary()[x].array[0], sizeof(Dtype));
            total += sizeof(Dtype);
            memcpy(data + total, &this->getBoundary()[x].array[1], sizeof(Dtype));
            total += sizeof(Dtype);

        }

        for(size_t x = 0; x < getDatasetCardinality(); x++)
        {


            Instance* inst = getDataset()->getInstance(x);
            u_int32_t oid = inst->getOID();

            memcpy(data + total, &oid, sizeof(u_int32_t));
            total += sizeof(u_int32_t);

            for(size_t y = 0; y < getDatasetDimensionality(); y++)
            {

                memcpy(data + total, &inst->getData()[y], sizeof(double));
                total += sizeof(double);

            }

        }

    }

    return data;

}



template<class Dtype>
void LeafNode<Dtype>::unserialize(u_char* data)
{

    u_int32_t nodeID = 0, datasetCardinality = 0, datasetDimensionality = 0, datasetSeed = 0, boundsSize = 0, total = 0;
    double dl;
    Dtype arr[2];

    memcpy(&nodeID, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);
    memcpy(&datasetCardinality, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);
    memcpy(&datasetDimensionality, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);
    memcpy(&datasetSeed, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);
    memcpy(&boundsSize, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);

    this->setNodeID((size_t)nodeID);
    setSerializeVariables((size_t)datasetCardinality, (size_t)datasetDimensionality, (size_t)datasetSeed, (size_t)boundsSize);
    this->setBoundary(std::vector<DynamicArray<Dtype>>(getBoundsSize()));

    Instance** dataAux = new Instance*[getDatasetCardinality()];

    for(size_t x = 0; x < getDatasetCardinality(); x++)
    {

        dataAux[x] = new Instance(x, getDatasetDimensionality());

    }

    for(size_t x = 0; x < getBoundsSize(); x++)
    {

        memcpy(&arr[0], data + total, sizeof(Dtype));
        total += sizeof(Dtype);
        memcpy(&arr[1], data + total, sizeof(Dtype));
        total += sizeof(Dtype);

        this->setBounds(DynamicArray<Dtype>(arr), x);

    }

    for(size_t x = 0; x < getDatasetCardinality(); x++)
    {

        u_int32_t oid = 0;
        memcpy(&oid, data + total, sizeof(u_int32_t));
        total += sizeof(u_int32_t);

        dataAux[x]->setOID(oid);

        for(size_t y = 0; y < getDatasetDimensionality(); y++)
        {

            memcpy(&dl, data + total, sizeof(double));
            total += sizeof(double);

            dataAux[x]->set(y, dl);

        }

    }

    setDataset(new Dataset(dataAux, getDatasetCardinality(), getDatasetDimensionality()));
    dataset->setSeed(getDatasetSeed());


}



#endif // LEAFNODE_H
