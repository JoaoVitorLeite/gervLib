#include "SSSPivots.h"


SSSPivots::SSSPivots()
{

    setAlpha(0.35);
    setPivotType(PIVOT_TYPE::SSS);

}


SSSPivots::~SSSPivots()
{


}


void SSSPivots::setAlpha(double alpha)
{

    this->alpha = alpha;

}


double SSSPivots::getAlpha()
{

    return alpha;

}


void SSSPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    size_t drop = 2, currentPivot = 0, p1, index = 0, count = 0;
    size_t* pvtIndex = new size_t[getNumberOfPivots()+drop];
    size_t* aux;
    double max = std::numeric_limits<double>::min(), dist, threshold;

    for(size_t x = 0; x < (getNumberOfPivots()+drop); x++)
        pvtIndex[x] = 0;

    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        for(size_t y = 0; y < sample->getCardinality(); y++)
        {

            if(x < y)
            {

                dist = df->getDistance(*sample->instance(x), *sample->instance(y));

                if(dist > max)
                    max = dist;

            }

        }

    }

    threshold = max * getAlpha();

    aux = uniqueRandomNumber(0, sample->getCardinality(), 1, getSeed());
    p1 = aux[0];
    pvtIndex[currentPivot] = p1;
    currentPivot++;

    while(index < sample->getCardinality())
    {

        count = 0;

        for(size_t x = 0; x < currentPivot; x++)
        {

            dist = df->getDistance(*sample->instance(index), *sample->instance(pvtIndex[x]));

            if(dist >= threshold)
                count++;

        }

        if(count == currentPivot)
        {

            pvtIndex[currentPivot] = index;
            currentPivot++;

        }

        if((currentPivot-drop) == getNumberOfPivots())
            break;
        else
            index++;

    }

    for(size_t x = drop; x < (getNumberOfPivots()+drop); x++)
        setPivot(sample->instance(pvtIndex[x]), x-drop);

    delete [] (aux);
    delete [] (pvtIndex);

}


void SSSPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, double alpha)
{

    setAlpha(alpha);
    generatePivots(sample, df, nPivots);

}

