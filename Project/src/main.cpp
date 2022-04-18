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

    Dataset* dataset = new Dataset("../datasets/ScalableColor.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    size_t size = 2000, cnt = 0;
    double sum = 0, mean = 0, stdev = 0;

    for(size_t x = 0; x < size; x++)
    {

        for(size_t y = x+1; y < size; y++)
        {

            sum += df->getDistance(*dataset->getInstance(x), *dataset->getInstance(y));
            cnt++;

        }

        if(x % 500 == 0)
            cout << "..." << endl;

    }

    mean = sum/cnt;
    cout << "MEAN = " << mean << endl;

    for(size_t x = 0; x < size; x++)
    {

        for(size_t y = x+1; y < size; y++)
        {

            double dist = df->getDistance(*dataset->getInstance(x), *dataset->getInstance(y));
            stdev += (dist-mean)*(dist-mean);

        }

        if(x % 500 == 0)
            cout << "..." << endl;

    }

    stdev /= cnt;
    cout << "STD = " << stdev << endl;

    cout << "ANS = " << (mean*mean)/(2*stdev) << endl;




    return 0;

}

