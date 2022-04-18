#include "PCAPivots.h"


PCAPivots::PCAPivots()
{

    setPivotType(PIVOT_TYPE::PCA);


}


PCAPivots::~PCAPivots()
{


}


void PCAPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    double max = std::numeric_limits<double>::min();
    double min = std::numeric_limits<double>::max();

    Eigen::MatrixXd A;
    A.resize(sample->getCardinality(), sample->getCardinality());

    for(size_t i = 0; i < sample->getCardinality(); i++)
    {

        for(size_t j = 0; j < sample->getCardinality(); j++)
        {

            if(i < j)
            {

                A(i,j) = df->getDistance(*sample->instance(i), *sample->instance(j));
                A(j,i) = A(i,j);

                if(A(i,j) > max) max = A(i,j);
                if(A(i,j) < min) min = A(i,j);

            }

            if(i == j) A(i,j) = 0.0;

        }

    }

    for(size_t i = 0; i < sample->getCardinality(); i++)
    {

        for(size_t j = 0; j < sample->getCardinality(); j++)
        {

            if(i < j)
            {

                A(i,j) = (A(i,j) - min)/(max - min);
                A(j,i) = A(i,j);

            }

        }

    }

    Eigen::EigenSolver<Eigen::MatrixXd> s(A);
    Eigen::VectorXd eigenValues = s.eigenvalues().real();

    std::vector<std::pair<double, long>> v;

    for(long i = 0; i < eigenValues.size(); i++)
    {

        std::pair<double, long> tupleAux(eigenValues[i], i);
        v.push_back(tupleAux);

    }

    std::sort(v.begin(), v.end(), [](const std::pair<double, long>& a, const std::pair<double, long>& b){ return std::get<0>(a) > std::get<0>(b); });

    for(size_t x = 0; x < getNumberOfPivots(); x++)
        setPivot(sample->instance(v[x].second), x);

}
