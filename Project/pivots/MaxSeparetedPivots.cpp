#include "MaxSeparetedPivots.h"


MaxSeparetedPivots::MaxSeparetedPivots()
{

    setPivotType(PIVOT_TYPE::MAXSEPARETED);

}


MaxSeparetedPivots::~MaxSeparetedPivots()
{


}


void MaxSeparetedPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    size_t drop = 2, currentPivot = 0, pos = 0, p1;
    bool* bitmap = new bool[sample->getCardinality()];
    size_t* pvtIndex = new size_t[getNumberOfPivots()+drop];
    size_t* aux;
    double max = std::numeric_limits<double>::min(), dist, sum = 0;

    for(size_t x = 0; x < sample->getCardinality(); x++)
        bitmap[x] = false;

    for(size_t x = 0; x < (getNumberOfPivots()+drop); x++)
        pvtIndex[x] = 0;

    aux = uniqueRandomNumber(0, sample->getCardinality(), 1, getSeed());
    p1 = aux[0];
    bitmap[p1] = true;
    pvtIndex[currentPivot] = p1;
    currentPivot++;

    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        dist = df->getDistance(*sample->instance(p1), *sample->instance(x));

        if(dist > max)
        {

            max = dist;
            pos = x;

        }

    }

    bitmap[pos] = true;
    pvtIndex[currentPivot] = pos;
    currentPivot++;

    while((currentPivot-drop) < getNumberOfPivots())
    {

        max = std::numeric_limits<double>::min();

        for(size_t x = 0; x < sample->getCardinality(); x++)
        {

            if(!bitmap[x])
            {

                sum = 0;

                for(size_t y = 0; y < currentPivot; y++)
                    sum += df->getDistance(*sample->instance(x), *sample->instance(pvtIndex[y]));

                if(sum > max)
                {

                    max = sum;
                    pos = x;

                }

            }

        }

        bitmap[pos] = true;
        pvtIndex[currentPivot] = pos;
        currentPivot++;

    }

    for(size_t x = drop; x < (getNumberOfPivots()+drop); x++)
        setPivot(sample->instance(pvtIndex[x]), x-drop);


    delete [] (bitmap);
    delete [] (pvtIndex);

}

