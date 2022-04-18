#include "TestSequentialScan.h"


void TestSequentialScan::initTestCase()
{


}


void TestSequentialScan::cleanupTestCase()
{


}


void TestSequentialScan::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(6), k);

    comp[0] = 6;
    comp[1] = 9;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(3), k);

    comp[0] = 3;
    comp[1] = 0;
    comp[2] = 5;
    comp[3] = 4;
    comp[4] = 1;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(4), k);

    comp[0] = 4;
    comp[1] = 1;
    comp[2] = 0;
    comp[3] = 5;
    comp[4] = 3;
    comp[5] = 9;
    comp[6] = 8;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(14), k);

    comp[0] = 14;
    comp[1] = 2;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(0), k);

    comp[0] = 0;
    comp[1] = 2;
    comp[2] = 10;
    comp[3] = 7;
    comp[4] = 14;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(8), k);

    comp[0] = 8;
    comp[1] = 3;
    comp[2] = 2;
    comp[3] = 4;
    comp[4] = 7;
    comp[5] = 14;
    comp[6] = 13;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(10), k);

    comp[0] = 10;
    comp[1] = 0;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(4), k);

    comp[0] = 4;
    comp[1] = 7;
    comp[2] = 11;
    comp[3] = 18;
    comp[4] = 8;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestSequentialScan::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    SequentialScan sq = SequentialScan();
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knn(sample, df, sample->instance(19), k);

    comp[0] = 19;
    comp[1] = 13;
    comp[2] = 11;
    comp[3] = 3;
    comp[4] = 18;
    comp[5] = 5;
    comp[6] = 8;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}

