#ifndef SSSPIVOTS_H
#define SSSPIVOTS_H

#include <Pivot.h>

class SSSPivots : public Pivot
{

    private:

        double alpha;

    public:

        SSSPivots();
        SSSPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, double alpha = 0.35) : Pivot(){

            setPivotType(PIVOT_TYPE::SSS);
            generatePivots(sample,function,nPivots,alpha);

        }
        SSSPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed, double alpha = 0.35) : Pivot(){

            setPivotType(PIVOT_TYPE::SSS);
            setSeed(seed);
            generatePivots(sample,function,nPivots,alpha);

        }
        ~SSSPivots();

        void setAlpha(double alpha);

        double getAlpha();

        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots);
        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots, double alpha);

};

#endif // SSSPIVOTS_H
