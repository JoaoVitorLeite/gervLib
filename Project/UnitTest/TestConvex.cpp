#include "TestConvex.h"


void TestConvex::initTestCase()
{

}


void TestConvex::cleanupTestCase()
{


}


void TestConvex::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(1105);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 7;
    pvtIndex[1] = 1;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(154);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 2;
    pvtIndex[1] = 6;
    pvtIndex[2] = 9;
    pvtIndex[3] = 8;
    pvtIndex[4] = 0;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);


}


void TestConvex::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(1324);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 7;
    pvtIndex[1] = 1;
    pvtIndex[2] = 9;
    pvtIndex[3] = 0;
    pvtIndex[4] = 4;
    pvtIndex[5] = 3;
    pvtIndex[6] = 5;


    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(3731);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 11;
    pvtIndex[1] = 12;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(36);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 0;
    pvtIndex[1] = 9;
    pvtIndex[2] = 7;
    pvtIndex[3] = 6;
    pvtIndex[4] = 4;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(387);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 0;
    pvtIndex[1] = 5;
    pvtIndex[2] = 7;
    pvtIndex[3] = 9;
    pvtIndex[4] = 1;
    pvtIndex[5] = 13;
    pvtIndex[6] = 14;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(1500);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 6;
    pvtIndex[1] = 16;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(795);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 12;
    pvtIndex[1] = 7;
    pvtIndex[2] = 6;
    pvtIndex[3] = 16;
    pvtIndex[4] = 9;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestConvex::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(915);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 12;
    pvtIndex[1] = 6;
    pvtIndex[2] = 16;
    pvtIndex[3] = 7;
    pvtIndex[4] = 14;
    pvtIndex[5] = 9;
    pvtIndex[6] = 19;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}

void TestConvex::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(1105);
    pvt->generatePivots(sample,df,2);
    pvt->saveToFile("../testPivot.dat");

    ConvexPivots* test = new ConvexPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestConvex::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(36);
    pvt->generatePivots(sample,df,5);
    pvt->saveToFile("../testPivot.dat");

    ConvexPivots* test = new ConvexPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestConvex::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    ConvexPivots* pvt = new ConvexPivots();
    pvt->setSeed(915);
    pvt->generatePivots(sample,df,7);
    pvt->saveToFile("../testPivot.dat");

    ConvexPivots* test = new ConvexPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}
