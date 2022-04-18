#include "MaxVariancePivots.h"


MaxVariancePivots::MaxVariancePivots()
{

    setPivotType(PIVOT_TYPE::MAXVARIANCE);


}


MaxVariancePivots::~MaxVariancePivots()
{


}


void MaxVariancePivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{

    setNumberOfPivots(nPivots);

    std::tuple<Instance**, Instance**, size_t, size_t> split = sample->splitTrainTest(0.5,0.5, getSeed());

    double mean, sum;
    std::vector<std::pair<Instance*, double>> v;

    for(size_t x = 0; x < std::get<2>(split); x++)
    {

        mean = 0, sum = 0;

        for(size_t y = 0; y < std::get<3>(split); y++)
            mean += df->getDistance(*std::get<0>(split)[x], *std::get<1>(split)[y]);

        mean /= std::get<3>(split)*1.0;

        for(size_t z = 0; z < std::get<3>(split); z++)
        {

            double dist = df->getDistance(*std::get<0>(split)[x], *std::get<1>(split)[z]);
            sum += (dist-mean)*(dist-mean);

        }

        sum /= std::get<3>(split)*1.0;

        v.push_back(std::make_pair(std::get<0>(split)[x], sum));

    }

    std::sort(v.begin(), v.end(), [](const std::pair<Instance*, double> &p1, const std::pair<Instance*, double> &p2){ return p1.second > p2.second; });

    for(size_t z = 0; z < getNumberOfPivots(); z++)
        setPivot(v[z].first, z);

    v.clear();

}







//MaxVariancePivots::MaxVariancePivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots)
//{
//    this->nPivots = nPivots;
//    this->currentPivot = 0;
//    this->pivotType = PIVOT_TYPE::MAXVARIANCE_PIVOTS;
//    this->pivots = new Instance*[this->nPivots];
//    this->seed = 0;
//    this->sample = sample;
//    this->df = function;
//}

//MaxVariancePivots::MaxVariancePivots(Dataset* sample, DistanceFunction<Instance>* function, size_t nPivots, unsigned int seed)
//{
//    this->nPivots = nPivots;
//    this->currentPivot = 0;
//    this->pivotType = PIVOT_TYPE::MAXVARIANCE_PIVOTS;
//    this->pivots = new Instance*[this->nPivots];
//    this->seed = seed;
//    this->sample = sample;
//    this->df = function;
//}

//MaxVariancePivots::MaxVariancePivots()
//{
//    this->nPivots = 0;
//    this->currentPivot = 0;
//    this->pivotType = PIVOT_TYPE::MAXVARIANCE_PIVOTS;
//    this->pivots = nullptr;
//    this->seed = 0;
//    this->sample = nullptr;
//    this->df = nullptr;
//}

//Instance* MaxVariancePivots::getNextPivot()
//{
//    return Pivot::getNextPivot();
//}

//Instance* MaxVariancePivots::getPivot(size_t pos)
//{
//    return Pivot::getPivot(pos);
//}

//void MaxVariancePivots::generatePivots(Dataset* sample, DistanceFunction<Instance>* df, size_t nPivots)
//{

//    setNumberOfPivots(nPivots);

//    std::tuple<Instance**, Instance**, size_t, size_t> aux = sample->splitTrainTest(0.5,0.5,getSeed());

//    Instance** candidates = std::get<0>(aux);
//    Instance** comp = std::get<1>(aux);
//    size_t candidatesSize = std::get<2>(aux);
//    size_t compSize = std::get<3>(aux);

//    //for(size_t i = 0; i < candidatesSize; i++) std::cout << candidates[i]->toStringWithOID() << std::endl;

//    //std::cout << "\n\n";

//    //for(size_t i = 0; i < candidatesSize; i++) std::cout << comp[i]->toStringWithOID() << std::endl;

//    std::vector<std::pair<Instance*, double>> v;

//    for(size_t c = 0; c < candidatesSize; c++){

//        double mean = 0, sum = 0;

//        for(size_t i = 0; i < compSize; i++) mean += df->getDistance(*candidates[c], *comp[i]);

//        mean /= compSize*1.0;

//        for(size_t i = 0; i < compSize; i++){
//            double dist = df->getDistance(*candidates[c], *comp[i]);
//            sum += (dist-mean)*(dist-mean);
//        }

//        sum /= compSize*1.0;

//        v.push_back(std::make_pair(candidates[c], sum));
//    }

//    std::sort(v.begin(), v.end(),
//              [](const std::pair<Instance*, double> &p1, const std::pair<Instance*, double> &p2){ return p1.second > p2.second; });

//    std::cout << "\n\n";
//    for(size_t z = 0; z < getNumberOfPivots(); z++){
//        setPivot(v[z].first, z);
//        //std::cout << "DEBUG = " << v[z].first->getOID() << " - " << v[z].second << std::endl;
//        //this->pivots[z] = v[z].first;
//    }

//}

//void MaxVariancePivots::setNumberOfPivots(const size_t &value)
//{
//    Pivot::setNumberOfPivots(value);
//}

//void MaxVariancePivots::setSeed(unsigned int seed)
//{
//    Pivot::setSeed(seed);
//}

//size_t MaxVariancePivots::getNumberOfPivots() const
//{
//    return Pivot::getNumberOfPivots();
//}

//unsigned int MaxVariancePivots::getSeed()
//{
//    return Pivot::getSeed();
//}
