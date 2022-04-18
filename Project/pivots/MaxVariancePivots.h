#ifndef MAXVARIANCEPIVOTS_H
#define MAXVARIANCEPIVOTS_H

#include <Pivot.h>

class MaxVariancePivots : public Pivot
{

    public:

        MaxVariancePivots();
        MaxVariancePivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::MAXVARIANCE);
            generatePivots(sample, function, nPivots);

        }
        MaxVariancePivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::MAXVARIANCE);
            setSeed(seed);
            generatePivots(sample, function, nPivots);

        }
        ~MaxVariancePivots();

        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots);



};

#endif // MAXVARIANCEPIVOTS_H
