#include "TestMaxVariance.h"


void TestMaxVariance::initTestCase()
{

}


void TestMaxVariance::cleanupTestCase()
{


}


void TestMaxVariance::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(503);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 2;
    pvtIndex[1] = 1;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(19);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 6;
    pvtIndex[1] = 1;
    pvtIndex[2] = 4;
    pvtIndex[3] = 0;
    pvtIndex[4] = 3;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);


}


//void TestMaxVariance::test3()
//{

//    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
//    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
//    MaxVariancePivots* pvt = new MaxVariancePivots();
//    pvt->setSeed(10341);
//    pvt->generatePivots(sample, df,7);

//    size_t* pvtIndex = new size_t[7];
//    pvtIndex[0] = 0;
//    pvtIndex[1] = 4;
//    pvtIndex[2] = 8;
//    pvtIndex[3] = 1;
//    pvtIndex[4] = 2;
//    pvtIndex[5] = 3;
//    pvtIndex[6] = 7;


//    for(size_t x = 0; x < 7; x++)
//    {

//        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

//    }

//    delete (sample);
//    delete (df);

//}


void TestMaxVariance::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(524);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 1;
    pvtIndex[1] = 13;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(8);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 12;
    pvtIndex[1] = 1;
    pvtIndex[2] = 0;
    pvtIndex[3] = 2;
    pvtIndex[4] = 14;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(8037);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 9;
    pvtIndex[1] = 3;
    pvtIndex[2] = 12;
    pvtIndex[3] = 13;
    pvtIndex[4] = 4;
    pvtIndex[5] = 14;
    pvtIndex[6] = 8;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(31);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 2;
    pvtIndex[1] = 1;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(3148);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 0;
    pvtIndex[1] = 1;
    pvtIndex[2] = 12;
    pvtIndex[3] = 3;
    pvtIndex[4] = 5;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(555);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 14;
    pvtIndex[1] = 2;
    pvtIndex[2] = 6;
    pvtIndex[3] = 10;
    pvtIndex[4] = 3;
    pvtIndex[5] = 7;
    pvtIndex[6] = 1;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestMaxVariance::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(503);
    pvt->generatePivots(sample,df,2);
    pvt->saveToFile("../testPivot.dat");

    MaxVariancePivots* test = new MaxVariancePivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestMaxVariance::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(8);
    pvt->generatePivots(sample,df,5);
    pvt->saveToFile("../testPivot.dat");

    MaxVariancePivots* test = new MaxVariancePivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestMaxVariance::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    MaxVariancePivots* pvt = new MaxVariancePivots();
    pvt->setSeed(555);
    pvt->generatePivots(sample,df,7);
    pvt->saveToFile("../testPivot.dat");

    MaxVariancePivots* test = new MaxVariancePivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}
