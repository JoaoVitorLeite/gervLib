#ifndef RANDOMPIVOTS_H
#define RANDOMPIVOTS_H

#include <Pivot.h>

class RandomPivots : public Pivot {

    public:
        RandomPivots();
        RandomPivots(Dataset *sample, size_t nPivots) : Pivot(){

            setPivotType(PIVOT_TYPE::RANDOM);
            generatePivots(sample, NULL, nPivots);
        }
        RandomPivots(Dataset *sample, size_t nPivots, size_t seed) : Pivot(){

            setPivotType(PIVOT_TYPE::RANDOM);
            setSeed(seed);
            generatePivots(sample, NULL, nPivots);
        }



        ~RandomPivots();

        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots);
        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, size_t seed);
};

#endif // RANDOMPIVOTS_H
