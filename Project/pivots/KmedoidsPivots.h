#ifndef KMEDOIDSPIVOTS_H
#define KMEDOIDSPIVOTS_H

#include <Pivot.h>
#include <Kmedoids.h>

class KmedoidsPivots : public Pivot
{

    private:

        size_t nIterations;

    public:

        KmedoidsPivots();
        KmedoidsPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots) : Pivot()
        {

            setNumberOfIterations(500);
            setPivotType(PIVOT_TYPE::KMEDOIDS);
            generatePivots(sample, function, nPivots);

        }
        KmedoidsPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed) : Pivot()
        {

            setPivotType(PIVOT_TYPE::KMEDOIDS);
            setSeed(seed);
            generatePivots(sample, function, nPivots);

        }
        KmedoidsPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t seed, size_t nIterations) : Pivot()
        {

            setPivotType(PIVOT_TYPE::KMEDOIDS);
            setSeed(seed);
            setNumberOfIterations(nIterations);
            generatePivots(sample, function, nPivots);

        }
        ~KmedoidsPivots();

        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots);
        void generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots, size_t nItearations);

        void setNumberOfIterations(size_t value);

        size_t getNumberOfIterations();


};

#endif // KMEDOIDSPIVOTS_H
