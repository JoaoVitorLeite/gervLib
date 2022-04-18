#include "KmedoidsPivots.h"


KmedoidsPivots::KmedoidsPivots()
{

    setNumberOfIterations(500);
    setPivotType(PIVOT_TYPE::KMEDOIDS);

}

KmedoidsPivots::~KmedoidsPivots()
{

}


void KmedoidsPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    Kmedoids* aux = new Kmedoids();
    aux->setSeed(getSeed());
    aux->setNumberOfIterations(getNumberOfIterations());

    aux->run(sample, df, nPivots);

    for(size_t x = 0; x < getNumberOfPivots(); x++)
        setPivot(aux->getCluster(x)->getMedoid(), x);

    delete (aux);

}


void KmedoidsPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, size_t nItearations)
{

    setNumberOfIterations(nItearations);
    generatePivots(sample, df, nPivots);

}


void KmedoidsPivots::setNumberOfIterations(size_t value)
{

    nIterations = value;

}


size_t KmedoidsPivots::getNumberOfIterations()
{

    return nIterations;

}

