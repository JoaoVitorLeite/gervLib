#ifndef INDEX_H
#define INDEX_H

#include <Dataset.h>
#include <vector>



struct PairResult
{

    size_t index;
    double distance;

    PairResult(size_t index_, double distance_)
    {

        index = index_;
        distance = distance_;

    }

    PairResult()
    {

        index = 0;
        distance = -1;

    }

};



//template<class Dtype>
class Index{

    public:

        virtual size_t getDiskAccess() = 0;
        virtual size_t getDistanceCount() = 0;
        virtual void knn(Dataset* train, Instance* query, size_t k, std::vector<PairResult> & ans) = 0;


};

#endif // INDEX_H
