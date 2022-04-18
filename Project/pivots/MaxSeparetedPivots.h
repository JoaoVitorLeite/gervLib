#ifndef MAXSEPARETEDPIVOTS_H
#define MAXSEPARETEDPIVOTS_H

#include <Pivot.h>

class MaxSeparetedPivots : public Pivot
{

    public:

        MaxSeparetedPivots();
        MaxSeparetedPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::MAXSEPARETED);
            generatePivots(sample, function, nPivots);

        }
        MaxSeparetedPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::MAXSEPARETED);
            setSeed(seed);
            generatePivots(sample, function, nPivots);

        }
        ~MaxSeparetedPivots();

        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots);

};

#endif // MAXSEPARETEDPIVOTS_H
