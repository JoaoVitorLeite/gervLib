#ifndef CONVEXPIVOTS_H
#define CONVEXPIVOTS_H

#include <Pivot.h>

class ConvexPivots : public Pivot
{

    public:
        ConvexPivots();
        ConvexPivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::CONVEX);
            generatePivots(sample, df, nPivots);

        }
        ConvexPivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::CONVEX);
            setSeed(seed);
            generatePivots(sample, df, nPivots);

        }
        ~ConvexPivots();

        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots);

};

#endif // CONVEXPIVOTS_H
