#include "TestGnat.h"


void TestGnat::initTestCase()
{

}


void TestGnat::cleanupTestCase()
{


}


void TestGnat::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(0);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 6;
    pvtIndex[1] = 2;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(17);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 7;
    pvtIndex[1] = 6;
    pvtIndex[2] = 1;
    pvtIndex[3] = 0;
    pvtIndex[4] = 9;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);


}


void TestGnat::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(1983);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 1;
    pvtIndex[1] = 7;
    pvtIndex[2] = 3;
    pvtIndex[3] = 9;
    pvtIndex[4] = 5;
    pvtIndex[5] = 4;
    pvtIndex[6] = 0;


    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(7659);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 0;
    pvtIndex[1] = 5;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(946);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 1;
    pvtIndex[1] = 7;
    pvtIndex[2] = 10;
    pvtIndex[3] = 5;
    pvtIndex[4] = 9;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(1000);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 1;
    pvtIndex[1] = 7;
    pvtIndex[2] = 12;
    pvtIndex[3] = 0;
    pvtIndex[4] = 5;
    pvtIndex[5] = 8;
    pvtIndex[6] = 4;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(510);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 18;
    pvtIndex[1] = 6;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(295);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 7;
    pvtIndex[1] = 1;
    pvtIndex[2] = 19;
    pvtIndex[3] = 18;
    pvtIndex[4] = 9;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(112);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 1;
    pvtIndex[1] = 18;
    pvtIndex[2] = 6;
    pvtIndex[3] = 9;
    pvtIndex[4] = 14;
    pvtIndex[5] = 16;
    pvtIndex[6] = 19;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestGnat::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(0);
    pvt->generatePivots(sample,df,2);
    pvt->saveToFile("../testPivot.dat");

    GnatPivots* test = new GnatPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestGnat::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(946);
    pvt->generatePivots(sample,df,5);
    pvt->saveToFile("../testPivot.dat");

    GnatPivots* test = new GnatPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestGnat::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    GnatPivots* pvt = new GnatPivots();
    pvt->setSeed(112);
    pvt->generatePivots(sample,df,7);
    pvt->saveToFile("../testPivot.dat");

    GnatPivots* test = new GnatPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}
