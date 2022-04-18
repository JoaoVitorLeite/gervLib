#ifndef SEQUENTIALSCAN_H
#define SEQUENTIALSCAN_H

#include <Dataset.h>
#include <queue>
#include <CompTuple.h>
#include <Hermes.h>

class SequentialScan
{

    public:
        SequentialScan();
        ~SequentialScan();

        std::pair<size_t, double>* knn(Dataset* sample, DistanceFunction<Instance>* df, Instance* query, size_t k);

};

#endif // SEQUENTIALSCAN_H
