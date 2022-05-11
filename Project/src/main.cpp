#include <iostream>
#include <Dataset.h>
#include <Hermes.h>
#include <Pivots.h>
#include <Laesa.h>
#include <SequentialScan.h>
#include <KdTree.h>
#include <OmniKdTree.h>

using namespace std;

int main(int argc, char *argv[])
{

    Dataset* dataset = new Dataset((new Dataset("../datasets/ulcer_SPP.csv", ","))->sample(1000, false), 1000, 12);
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* pvt = new RandomPivots(dataset, 2);

    //512kB/4MB ? Quantos caras posso colocar?
    //size_of -> 01 id, d dimensões (xkB) -> para 01 si
    //Logo, x si para 512kB
    OmniKdTree<double> omni = OmniKdTree<double>(dataset, df, pvt, 10);
    size_t k = 5;

//    for(size_t x = 0; x < dataset->getCardinality(); x++)
//    {

//        std::vector<PairResult> ans;
//        omni.knn(dataset, dataset->getInstance(x), k, ans);

//        std::vector<PairResult> ss;
//        for(size_t y = 0; y < dataset->getCardinality(); y++)
//            ss.push_back(PairResult(y, df->getDistance(*dataset->getInstance(y), *dataset->getInstance(x))));
//        std::sort(ss.begin(), ss.end(), [](PairResult a, PairResult b){
//            return a.distance < b.distance;
//        });
//        ss.resize(k);

//        for(size_t z = 0; z < k; z++)
//            if(ss[z].distance != ans[z].distance)
//                cout << "FALSE EM : " << x << endl;

//        cout << "DISK = " << omni.getDiskAccess() << endl;

//    }




    std::vector<PairResult> ans;
    omni.knn(dataset, dataset->getInstance(0), k, ans);
    cout << "\n\n\nDISK = " << omni.getDiskAccess() << endl;

    cout << "\n\n\n\nQUERY ANS = ";
    for(PairResult r : ans)
        cout << r.index << "," << r.distance << endl;
    cout << endl;


    std::vector<PairResult> ss;
    for(size_t x = 0; x < dataset->getCardinality(); x++)
        ss.push_back(PairResult(x, df->getDistance(*dataset->getInstance(x), *dataset->getInstance(0))));
    std::sort(ss.begin(), ss.end(), [](PairResult a, PairResult b){
        return a.distance < b.distance;
    });
    ss.resize(k);
    for(PairResult i : ss)
        cout << i.index << " / " << i.distance << endl;
    cout << endl;

    cout << "\nDISTANCIAS CALCULADAS PARA AUXILIAR DO DEBUG\n\n";

//    cout << "\n\n";
//    cout << 0 << " / " << df->getDistance(*dataset->getInstance(0), *dataset->getInstance(0)) << std::endl;
//    cout << 612 << " / " << df->getDistance(*dataset->getInstance(0), *dataset->getInstance(612)) << std::endl;
//    cout << 14 << " / " << df->getDistance(*dataset->getInstance(0), *dataset->getInstance(14)) << std::endl;
    cout << 365 << " / " << df->getDistance(*dataset->getInstance(365), *pvt->getPivot(0)) << std::endl;
    cout << 365 << " / " << df->getDistance(*dataset->getInstance(365), *dataset->getInstance(317)) << std::endl;

    cout << pvt->getPivot(0)->toString() << endl << pvt->getPivot(1)->toString() << endl;





    return 0;

}

