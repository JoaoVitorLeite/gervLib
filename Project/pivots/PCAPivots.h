#ifndef PCAPIVOTS_H
#define PCAPIVOTS_H

#include <Pivot.h>
#include <Eigenvalues>

class PCAPivots : public Pivot
{

    public:

        PCAPivots();
        PCAPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::PCA);
            generatePivots(sample,function,nPivots);

        }
        PCAPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::PCA);
            setSeed(seed);
            generatePivots(sample,function,nPivots);

        }

        ~PCAPivots();

        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots);

};

#endif // PCAPIVOTS_H
