#include "SelectionPivots.h"


SelectionPivots::SelectionPivots()
{

    setNumberOfGroups(5);
    setPivotType(PIVOT_TYPE::SELECTION);


}


SelectionPivots::~SelectionPivots()
{


}


void SelectionPivots::setNumberOfGroups(const size_t &value)
{

    nGroups = value;

}


size_t SelectionPivots::getNumberOfGroups() const
{

    return nGroups;

}


void SelectionPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfGroups(size_t(0.5*sample->getCardinality()));
    setNumberOfPivots(nPivots);

    double min = std::numeric_limits<double>::max();
    double length = ((getNumberOfPivots()*(getNumberOfPivots()-1))*1.0)/2.0;
    double mean = 0, dist;
    Instance** group = nullptr;

    srand(getSeed());

    for(size_t g = 0; g < getNumberOfGroups(); g++){

        group = sample->sample(getNumberOfPivots(), false, rand());
        mean = 0;

        for(size_t x = 0; x < getNumberOfPivots(); x++)
        {

            for(size_t y = 0; y < getNumberOfPivots(); y++)
            {

                if(x < y)
                {

                    dist = df->getDistance(*group[x], *group[y]);
                    mean += dist/length;

                }

            }

        }

        if(mean < min)
        {

            min = mean;
            setPivots(group);

        }


    }

}

void SelectionPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, size_t nGroups)
{

    setNumberOfGroups(nGroups);
    generatePivots(sample, df, nPivots);

}
