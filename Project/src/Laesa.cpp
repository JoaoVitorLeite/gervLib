#include "Laesa.h"

void Laesa::destroyLaesa(){

    if (laesaMatrix != nullptr){
        for(size_t x = 0; x < cardinality; x++)
            delete [] (laesaMatrix[x]);
        delete [] (laesaMatrix);
    }

//    if (pivot != nullptr){
//        delete [] (pivot);
//    }
}


Laesa::Laesa()
{

    cardinality = 0;
    df = nullptr;
    pivot = nullptr;
    laesaMatrix = nullptr;

}

Laesa::Laesa(Dataset* sample, DistanceFunction<Instance>* function, Pivot* pivot)
{

    cardinality = sample->getCardinality();
    this->df = function;
    this->pivot = pivot;

    laesaMatrix = new double*[cardinality];
    for(size_t x = 0; x < cardinality; x++){
        laesaMatrix[x] = new double[pivot->getNumberOfPivots()];
    }

    computeDistanceMatrix(sample);

}

Laesa::~Laesa(){

    destroyLaesa();
}



void Laesa::setPivots(Pivot *pivot)
{

    this->pivot = pivot;

}


void Laesa::setNumberOfPivots(const size_t value)
{

    pivot->setNumberOfPivots(value);

}


void Laesa::setSeed(size_t seed)
{

    pivot->setSeed(seed);

}


void Laesa::setCardinality(size_t value)
{

    cardinality = value;

}


void Laesa::setPivot(Pivot *pivot)
{

    this->pivot = pivot;

}


void Laesa::setLaesaMatrix(double **matrix)
{

    laesaMatrix = matrix;

}


void Laesa::setDistanceFunction(DistanceFunction<Instance> *df)
{

    this->df = df;

}


size_t Laesa::getNumberOfPivots() const
{

    return pivot->getNumberOfPivots();

}


Instance* Laesa::getPivot(size_t pos)
{

    return pivot->getPivot(pos);

}


u_int32_t Laesa::getDistCount() const
{

    return df->getDistanceCount();

}


size_t Laesa::getCardinality() const
{

    return cardinality;

}


size_t Laesa::getSerializedSize() const
{

    return 3*sizeof(size_t) + sizeof(PIVOT_TYPE) + pivotSerializedSize + (nPivots*cardinality*sizeof(double));

}


Pivot* Laesa::getPivot()
{

    return pivot;

}


double** Laesa::getLaesaMatrix()
{

    return laesaMatrix;

}


DistanceFunction<Instance>* Laesa::getDistanceFunction()
{

    return df;

}


void Laesa::generatePivots(Dataset* sample)
{

    pivot->generatePivots(sample, df, getNumberOfPivots());

}


void Laesa::computeDistanceMatrix(Dataset* sample)
{

    for(size_t x = 0; x < cardinality; x++)
    {

        for(size_t y = 0; y < getNumberOfPivots(); y++)
        {

            laesaMatrix[x][y] = df->getDistance(*sample->instance(x), *pivot->getPivot(y));

        }

    }

}


std::pair<size_t, double>* Laesa::knn(Dataset* sample, Instance *query, size_t k)
{

    df->resetStatistics();
    double radius = std::numeric_limits<double>::max(), distToPivot, lowerBound, upperBound;
    std::pair<size_t, double>* ans = new std::pair<size_t, double>[k];
    std::priority_queue<std::pair<size_t, double>, std::vector<std::pair<size_t, double>>, LessTuple<1, size_t, double>> pq;
    bool *bitmap = new bool[cardinality];
    size_t pos = 0;

    //Inicializa bitmap
    for (size_t x = 0; x < sample->getCardinality(); x++)
        bitmap[x] = false;


    for(size_t p = 0; p < pivot->getNumberOfPivots(); p++)
    {

        if(!bitmap[pivot->getPivot(p)->getOID()])
        {

            distToPivot = this->df->getDistance(*pivot->getPivot(p), *query);

            for(size_t i = 0; i < cardinality; i++)
            {

                if(!bitmap[i])
                {

                    lowerBound = std::abs(distToPivot - laesaMatrix[i][p]);
                    upperBound = distToPivot + laesaMatrix[i][p];

                    if(upperBound <= radius)
                    {

                        pq.push(std::pair<size_t, double>(i, this->df->getDistance(*sample->instance(i), *query)));

                        if(pq.size() > k)
                        {

                            pq.pop();
                            radius = pq.top().second;

                        }

                        bitmap[i] = true;

                    }

                    if(lowerBound > radius)
                        bitmap[i] = true;

                }

            }

        }

    }

    for(size_t z = 0; z < cardinality; z++)
    {

        if(!bitmap[z])
        {

            pq.push(std::pair<size_t, double>(z, this->df->getDistance(*sample->instance(z), *query)));

            if(pq.size() > k) pq.pop();

        }

    }

    pos = k-1;
    while(!pq.empty())
    {

        ans[pos--] = pq.top();
        pq.pop();

    }

    delete [] (bitmap);

    return ans;
}


std::pair<size_t, double>* Laesa::knnShapiro(Dataset* sample, Instance *query, size_t k)
{

    df->resetStatistics();
    double radius = std::numeric_limits<double>::max(), distToPivot, lowerBound, upperBound, dist;
    std::pair<size_t, double>* ans = new std::pair<size_t, double>[k];
    std::priority_queue<std::pair<size_t, double>, std::vector<std::pair<size_t, double>>, LessTuple<1, size_t, double>> pq;
    bool *bitmap = new bool[cardinality];
    //Repensar o map...
    std::vector<std::pair<size_t, double>> shapiroAux;

    for(size_t x = 0; x < pivot->getNumberOfPivots(); x++)
        shapiroAux.push_back(std::make_pair(x, df->getDistance(*query, *pivot->getPivot(x))));
    std::sort(shapiroAux.begin(), shapiroAux.end(), [](const std::pair<size_t, double> &p1, const std::pair<size_t, double> &p2){ return p1.second < p2.second; });

    //Inicializa bitmap
    for (size_t x = 0; x < sample->getCardinality(); x++)
        bitmap[x] = false;

    for(size_t p = 0; p < shapiroAux.size(); p++){
        if(!bitmap[pivot->getPivot(shapiroAux[p].first)->getOID()]){

            distToPivot = shapiroAux[p].second;
            for(size_t x = 0; x < sample->getCardinality(); x++){

                if(!bitmap[x]){
                    lowerBound = std::abs(distToPivot - laesaMatrix[x][shapiroAux[p].first]);
                    upperBound = distToPivot + laesaMatrix[x][shapiroAux[p].first];

                    if(upperBound <= radius)
                    {

                        pq.push(std::pair<size_t, double>(x, this->df->getDistance(*sample->instance(x), *query)));

                        if(pq.size() > k)
                        {

                            pq.pop();
                            radius = pq.top().second;

                        }

                        bitmap[x] = true;

                    }

                    if(lowerBound > radius)
                        bitmap[x] = true;

                }
            }
        }
    }

    for(size_t x = 0; x < sample->getCardinality(); x++){

        if(!bitmap[x]){
            dist = df->getDistance(*sample->instance(x), *query);
            if (dist < radius){
                pq.push(std::make_pair(x, df->getDistance(*sample->instance(x), *query)));
                if(pq.size() > k){
                    pq.pop();
                    radius = pq.top().second;
                }
            }
        }
    }

    for(size_t x = k-1; !pq.empty(); x--){
        ans[x] = pq.top();
        pq.pop();
    }

    delete [] (bitmap);
    shapiroAux.clear();

    return ans;

}


bool Laesa::isEqual(Laesa *other)
{

    bool answer = true;

    if((getNumberOfPivots() != other->getNumberOfPivots()) || (getCardinality() != other->getCardinality()) || (!getPivot()->isEqual(other->getPivot())))
        answer = false;
    else
    {

        for(size_t x = 0; (x < getCardinality()) && (answer); x++)
        {

            for(size_t y = 0; (y < getNumberOfPivots()) && (answer); y++)
            {

                if(getLaesaMatrix()[x][y] != other->getLaesaMatrix()[x][y])
                    answer = false;

            }

        }

    }

    return answer;

}


char* Laesa::serialize()
{

    /*
    Cardinality
    PivotSerializedSize
    NPivots
    PIVOT TYPE
    Pivot
    LaesaMatrix
    */

    pivotSerializedSize = pivot->getSerializedSize();
    nPivots = pivot->getNumberOfPivots();
    char* dataOut = nullptr;

    if(dataOut == nullptr)
    {

        size_t count = 0;
        dataOut = new char[getSerializedSize()];
        PIVOT_TYPE aux = pivot->getPivotType();

        memcpy(dataOut, &cardinality, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t), &pivotSerializedSize, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t)*2, &nPivots, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t)*3, &aux, sizeof(PIVOT_TYPE));
        memcpy(dataOut + sizeof(size_t)*3 + sizeof(PIVOT_TYPE), pivot->serialize(), pivotSerializedSize);


        for(size_t x = 0; x < getCardinality(); x++)
        {

            for(size_t p = 0; p < getNumberOfPivots(); p++)
            {

                memcpy(dataOut + sizeof(size_t)*3 + sizeof(PIVOT_TYPE) + pivotSerializedSize + count*sizeof(double), &laesaMatrix[x][p], sizeof(double));
                count++;

            }

        }


    }

    return dataOut;

}


void Laesa::unserialize(char *dataIn)
{

//    //Fazer switch com o pivotType
//    pivot = new RandomPivots(); //Problema -> tem que ler todos os métodos como random

    PIVOT_TYPE aux;

    memcpy(&cardinality, dataIn, sizeof(size_t));
    memcpy(&pivotSerializedSize, dataIn + sizeof(size_t), sizeof(size_t));
    memcpy(&nPivots, dataIn + sizeof(size_t)*2, sizeof(size_t));
    memcpy(&aux, dataIn + sizeof(size_t)*3, sizeof(PIVOT_TYPE));

    std::string names[] = {"RANDOM", "GNAT", "CONVEX", "KMEDOIDS", "MAXSEPARETED", "MAXVARIANCE", "SELECTION", "PCA", "SSS"};

    if(names[aux] == "RANDOM")
        pivot = new RandomPivots();
    else if(names[aux] == "GNAT")
        pivot = new GnatPivots();
    else if(names[aux] == "CONVEX")
        pivot = new ConvexPivots();
    else if(names[aux] == "KMEDOIDS")
        pivot = new KmedoidsPivots();
    else if(names[aux] == "MAXSEPARETED")
        pivot = new MaxSeparetedPivots();
    else if(names[aux] == "MAXVARIANCE")
        pivot = new MaxVariancePivots();
    else if(names[aux] == "SELECTION")
        pivot = new SelectionPivots();
    else if(names[aux] == "PCA")
        pivot = new PCAPivots();
    else if(names[aux] == "SSS")
        pivot = new SSSPivots();
    else
        throw std::invalid_argument("Can't read pivot type !_!");

    char* pivotRead = new char[pivotSerializedSize];

    memcpy(pivotRead, dataIn + sizeof(size_t)*3 + sizeof(PIVOT_TYPE), pivotSerializedSize);
    pivot->unserialize(pivotRead);

    size_t count = 0;

    if(laesaMatrix != nullptr)
        destroyLaesa();

    laesaMatrix = new double*[cardinality];
    for(size_t x = 0; x < cardinality; x++)
        laesaMatrix[x] = new double[nPivots];

    for(size_t x = 0; x < getCardinality(); x++)
    {

        for(size_t p = 0; p < getNumberOfPivots(); p++)
        {

            memcpy(&laesaMatrix[x][p], dataIn + sizeof(size_t)*3 + sizeof(PIVOT_TYPE) + pivotSerializedSize + count*sizeof(double), sizeof(double));
            count++;

        }

    }

}


void Laesa::saveToFile(std::string fileName)
{

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    char* ans = serialize();

    file.write(ans, getSerializedSize());
    file.close();

}


void Laesa::loadFromFile(std::string fileName)
{

    std::ifstream file(fileName, std::ios::in | std::ios::binary);

    char* aux = new char[3*sizeof(size_t)];
    file.read(aux, sizeof(size_t)*3);

    memcpy(&cardinality, aux, sizeof(size_t));
    memcpy(&pivotSerializedSize, aux + sizeof(size_t), sizeof(size_t));
    memcpy(&nPivots, aux + sizeof(size_t)*2, sizeof(size_t));

    file.seekg(0);
    char* ans = new char[getSerializedSize()];
    file.read(ans, getSerializedSize());

    unserialize(ans);

    file.close();

    delete [] (aux);
    delete [] (ans);

}




size_t Laesa::getDiskAccess()
{

    return 0;

}



size_t Laesa::getDistanceCount()
{

    return df->getDistanceCount();

}



void Laesa::knn(Dataset* train, Instance* query, size_t k, std::vector<PairResult> & ans)
{

    df->resetStatistics();
    ans.clear();
    double radius = std::numeric_limits<double>::max(), distToPivot, lowerBound, upperBound, dist;
    std::priority_queue<std::pair<size_t, double>, std::vector<std::pair<size_t, double>>, LessTuple<1, size_t, double>> pq;
    bool *bitmap = new bool[cardinality];

    std::vector<std::pair<size_t, double>> shapiroAux;

    for(size_t x = 0; x < pivot->getNumberOfPivots(); x++)
        shapiroAux.push_back(std::make_pair(x, df->getDistance(*query, *pivot->getPivot(x))));
    std::sort(shapiroAux.begin(), shapiroAux.end(), [](const std::pair<size_t, double> &p1, const std::pair<size_t, double> &p2){ return p1.second < p2.second; });

    //Inicializa bitmap
    for (size_t x = 0; x < train->getCardinality(); x++)
        bitmap[x] = false;

    for(size_t p = 0; p < shapiroAux.size(); p++){
        if(!bitmap[pivot->getPivot(shapiroAux[p].first)->getOID()]){

            distToPivot = shapiroAux[p].second;
            for(size_t x = 0; x < train->getCardinality(); x++){

                if(!bitmap[x]){
                    lowerBound = std::abs(distToPivot - laesaMatrix[x][shapiroAux[p].first]);
                    upperBound = distToPivot + laesaMatrix[x][shapiroAux[p].first];

                    if(upperBound <= radius)
                    {

                        pq.push(std::pair<size_t, double>(x, this->df->getDistance(*train->instance(x), *query)));

                        if(pq.size() > k)
                        {

                            pq.pop();
                            radius = pq.top().second;

                        }

                        bitmap[x] = true;

                    }

                    if(lowerBound > radius)
                        bitmap[x] = true;

                }
            }
        }
    }

    for(size_t x = 0; x < train->getCardinality(); x++){

        if(!bitmap[x]){
            dist = df->getDistance(*train->instance(x), *query);
            if (dist < radius){
                pq.push(std::make_pair(x, df->getDistance(*train->instance(x), *query)));
                if(pq.size() > k){
                    pq.pop();
                    radius = pq.top().second;
                }
            }
        }
    }

    ans.reserve(k);
    for(size_t x = k-1; !pq.empty(); x--)
    {

        std::pair<size_t, double> popItem = pq.top();
        pq.pop();
        ans[x] = PairResult(popItem.first, popItem.second);

    }

    delete [] (bitmap);
    shapiroAux.clear();

}
