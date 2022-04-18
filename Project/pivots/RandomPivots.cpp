#include "RandomPivots.h"


RandomPivots::~RandomPivots()
{

    setPivotType(PIVOT_TYPE::RANDOM);

}


RandomPivots::RandomPivots()
{

}


void RandomPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    //Gerar a lista de pivôs
    //Gerar uma lista de ids sem reposição de tamanha nPivots
    size_t *randomIds = uniqueRandomNumber(0, sample->getCardinality(), getNumberOfPivots(), getSeed());

    for(size_t x = 0; x < getNumberOfPivots(); x++)
        setPivot(sample->instance(randomIds[x]), x);


    delete[] randomIds;

}


void RandomPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, size_t seed)
{

    setSeed(seed);
    generatePivots(sample, df, nPivots);

}

