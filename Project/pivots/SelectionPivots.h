#ifndef SELECTIONPIVOTS_H
#define SELECTIONPIVOTS_H

#include <Pivot.h>

class SelectionPivots : public Pivot
{
    private:

        size_t nGroups;

    public:

        SelectionPivots();
        SelectionPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t nGroups) : Pivot(){

            setNumberOfGroups(nGroups);
            setPivotType(PIVOT_TYPE::SELECTION);
            generatePivots(sample, function, nPivots, nGroups);

        }
        SelectionPivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, size_t nGroups, size_t seed) : Pivot(){

            setNumberOfGroups(nGroups);
            setPivotType(PIVOT_TYPE::SELECTION);
            setSeed(seed);
            generatePivots(sample, function, nPivots, nGroups);

        }
        ~SelectionPivots();

        void setNumberOfGroups(const size_t &value);

        size_t getNumberOfGroups() const;

        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots);
        void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots, size_t nGroups);

};

#endif // SELECTIONPIVOTS_H
