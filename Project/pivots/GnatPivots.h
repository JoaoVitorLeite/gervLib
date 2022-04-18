#ifndef GNATPIVOTS_H
#define GNATPIVOTS_H

#include <Pivot.h>

class GnatPivots : public Pivot
{

    public:

        GnatPivots();
        GnatPivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::GNAT);
            generatePivots(sample, df, nPivots);

        }
        GnatPivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::GNAT);
            setSeed(seed);
            generatePivots(sample, df, nPivots);

        }

        ~GnatPivots();

        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots);

};

#endif // GNATPIVOTS_H
