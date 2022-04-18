#include "Kmedoids.h"


void Kmedoids::initializeClusters(Dataset* sample)
{

    size_t* randomIndex = uniqueRandomNumber(0, sample->getCardinality(), getNumberOfClusters(), getSeed());

    for(size_t x = 0; x < getNumberOfClusters(); x++)
        clusters[x]->setMedoid(sample->instance(randomIndex[x]));

}


void Kmedoids::reCenter(DistanceFunction<Instance>* df)
{

    double min = std::numeric_limits<double>::max(), total = 0, dist = 0;
    size_t index = 0, size = 0;

    for(size_t z = 0; z < getNumberOfClusters(); z++)
    {

        size = getCluster(z)->size();
        min = std::numeric_limits<double>::max();

        for(size_t x = 0; x < size; x++)
        {

            total = 0;

            for(size_t y = 0; y < size; y++)
            {

                if(x != y)
                {

                    dist = df->getDistance(*getCluster(z)->getInstance(x), *getCluster(z)->getInstance(y));
                    total += dist/((size-1)*1.0);

                }

            }

            if(total < min)
            {

                min = total;
                index = x;

            }

        }

        getCluster(z)->setMedoid(getCluster(z)->getInstance(index));

    }

}


void Kmedoids::assignment(Dataset* sample, DistanceFunction<Instance>* df)
{

    double min, dist;
    size_t index;

    for(size_t x = 0; x < getNumberOfClusters(); x++)
        getCluster(x)->clearSet();

    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        min = std::numeric_limits<double>::max();
        index = 0;

        for(size_t y = 0; y < getNumberOfClusters(); y++){

            dist = df->getDistance(*sample->instance(x), *getCluster(y)->getMedoid());

            if(dist < min)
            {

                min = dist;
                index = y;

            }

        }

        getCluster(index)->addInstance(sample->instance(x));

    }

}


Kmedoids::Kmedoids()
{

    nClusters = 0;
    iterations = 500;
    clusters = nullptr;
    seed = 0;

}


Kmedoids::~Kmedoids()
{

    if(clusters != nullptr)
    {

        for(size_t x = 0; x < getNumberOfClusters(); x++)
            delete (getCluster(x));

        delete [] clusters;
    }

}


void Kmedoids::setNumberOfClusters(size_t nClusters)
{

    this->nClusters = nClusters;
    clusters = new Cluster*[getNumberOfClusters()];

    for(size_t x = 0; x < getNumberOfClusters(); x++)
        clusters[x] = new Cluster();

}


void Kmedoids::setSeed(size_t seed)
{

    this->seed = seed;

}


void Kmedoids::setNumberOfIterations(size_t iterations)
{

    this->iterations = iterations;

}


size_t Kmedoids::getSeed()
{

    return seed;

}


size_t Kmedoids::getNumberOfClusters() const
{

    return nClusters;

}


size_t Kmedoids::getNumberOfIterations()
{

    return iterations;

}


Instance** Kmedoids::getMedoids()
{

    Instance** ans = nullptr;

    if(getNumberOfClusters() != 0)
    {

        ans = new Instance*[getNumberOfClusters()];

        for(size_t x = 0; x < getNumberOfClusters(); x++)
            ans[x] = getCluster(x)->getMedoid();

    }
    else
        throw std::invalid_argument("Number of cluster equal to 0 !_!");

    return ans;

}


Cluster* Kmedoids::getCluster(size_t pos)
{

    Cluster* ans = nullptr;

    if((getNumberOfClusters() != 0) && (pos < getNumberOfClusters()))
    {

        ans = clusters[pos];

    }
    else
        throw std::invalid_argument("Number of cluster equal to 0 !_!");

    return ans;

}



void Kmedoids::run(Dataset* sample, DistanceFunction<Instance>* df, size_t nClusters)
{

    setNumberOfClusters(nClusters);
    initializeClusters(sample);

    size_t ite = 0;
    size_t* aux1 = new size_t[getNumberOfClusters()];
    size_t* aux2 = new size_t[getNumberOfClusters()];

    for(size_t x = 0; x  < getNumberOfClusters(); x++)
    {

        aux1[x] = 0;
        aux2[x] = 0;

    }

    while(ite < getNumberOfIterations())
    {

        for(size_t x = 0; x < getNumberOfClusters(); x++)
            aux1[x] = getCluster(x)->getMedoid()->getOID();

        assignment(sample, df);
        reCenter(df);

        for(size_t y = 0; y < getNumberOfClusters(); y++)
            aux2[y] = getCluster(y)->getMedoid()->getOID();

        bool ans = true;

        for(size_t z = 0; z < getNumberOfClusters(); z++)
        {

            if(aux1[z] != aux2[z])
                ans = false;

        }

        if(ans)
            break;

        ite++;
    }

    delete [] aux1;
    delete [] aux2;

}

