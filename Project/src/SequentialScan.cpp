#include "SequentialScan.h"


SequentialScan::SequentialScan()
{


}


SequentialScan::~SequentialScan()
{


}


std::pair<size_t, double>* SequentialScan::knn(Dataset *sample, DistanceFunction<Instance> *df, Instance *query, size_t k)
{

    std::priority_queue<std::pair<size_t, double>, std::vector<std::pair<size_t, double>>, LessTuple<1, size_t, double>> pq;
    std::pair<size_t, double>* ans = new std::pair<size_t, double>[k];
    size_t pos = k-1;

    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        pq.push(std::make_pair(sample->instance(x)->getOID(), df->getDistance(*sample->instance(x), *query)));
        if(pq.size() > k) pq.pop();

    }

    while(!pq.empty())
    {

        ans[pos] = pq.top();
        pq.pop();
        pos--;

    }


    return ans;

}

