#include "TestLaesa.h"


void TestLaesa::initTestCase()
{


}


void TestLaesa::cleanupTestCase()
{


}


void TestLaesa::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(6), k);

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


void TestLaesa::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(3), k);

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


void TestLaesa::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(4), k);

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


void TestLaesa::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(14), k);

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


void TestLaesa::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(0), k);

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


void TestLaesa::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(8), k);

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


void TestLaesa::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(10), k);

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


void TestLaesa::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(4), k);

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


void TestLaesa::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa sq = Laesa(sample, df, p);
    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans = sq.knnShapiro(sample, sample->instance(19), k);

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


void TestLaesa::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa laesa1 = Laesa(sample, df, p);
    laesa1.saveToFile("../laesa.dat");

    Laesa laesa2 = Laesa();
    laesa2.loadFromFile("../laesa.dat");
    laesa2.setDistanceFunction(df);

    size_t k = 2;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans1 = laesa1.knnShapiro(sample, sample->instance(6), k);
    std::pair<size_t, double>* ans2 = laesa2.knnShapiro(sample, sample->instance(6), k);

    comp[0] = 6;
    comp[1] = 9;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans1[x].first);
        QCOMPARE(comp[x], ans2[x].first);


    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestLaesa::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa laesa1 = Laesa(sample, df, p);
    laesa1.saveToFile("../laesa.dat");

    Laesa laesa2 = Laesa();
    laesa2.loadFromFile("../laesa.dat");
    laesa2.setDistanceFunction(df);

    size_t k = 5;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans1 = laesa1.knnShapiro(sample, sample->instance(3), k);
    std::pair<size_t, double>* ans2 = laesa2.knnShapiro(sample, sample->instance(3), k);

    comp[0] = 3;
    comp[1] = 0;
    comp[2] = 5;
    comp[3] = 4;
    comp[4] = 1;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans1[x].first);
        QCOMPARE(comp[x], ans2[x].first);

    }

    delete (sample);
    delete (df);
    delete [] (comp);

}


void TestLaesa::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    Pivot* p = new RandomPivots(sample, 2);
    Laesa laesa1 = Laesa(sample, df, p);
    laesa1.saveToFile("../laesa.dat");

    Laesa laesa2 = Laesa();
    laesa2.loadFromFile("../laesa.dat");
    laesa2.setDistanceFunction(df);

    size_t k = 7;
    size_t* comp = new size_t[k];
    std::pair<size_t, double>* ans1 = laesa1.knnShapiro(sample, sample->instance(4), k);
    std::pair<size_t, double>* ans2 = laesa2.knnShapiro(sample, sample->instance(4), k);

    comp[0] = 4;
    comp[1] = 1;
    comp[2] = 0;
    comp[3] = 5;
    comp[4] = 3;
    comp[5] = 9;
    comp[6] = 8;

    for(size_t x = 0; x < k; x++)
    {

        QCOMPARE(comp[x], ans1[x].first);
        QCOMPARE(comp[x], ans2[x].first);


    }

    delete (sample);
    delete (df);
    delete [] (comp);

}
