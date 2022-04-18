#include "TestKmedoids.h"


void TestKmedoids::initTestCase()
{

}


void TestKmedoids::cleanupTestCase()
{


}


void TestKmedoids::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(602);
    pvt->generatePivots(sample, df, 2, 500);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 4;
    pvtIndex[1] = 8;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(6);
    pvt->generatePivots(sample, df, 5, 500);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 6;
    pvtIndex[1] = 8;
    pvtIndex[2] = 2;
    pvtIndex[3] = 5;
    pvtIndex[4] = 1;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);


}


void TestKmedoids::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(74);
    pvt->generatePivots(sample, df, 7, 500);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 6;
    pvtIndex[1] = 0;
    pvtIndex[2] = 5;
    pvtIndex[3] = 1;
    pvtIndex[4] = 2;
    pvtIndex[5] = 7;
    pvtIndex[6] = 4;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(714);
    pvt->generatePivots(sample, df, 2, 500);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 3;
    pvtIndex[1] = 2;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(1413);
    pvt->generatePivots(sample, df, 5, 500);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 1;
    pvtIndex[1] = 5;
    pvtIndex[2] = 3;
    pvtIndex[3] = 2;
    pvtIndex[4] = 13;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(3);
    pvt->generatePivots(sample, df, 7, 500);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 4;
    pvtIndex[1] = 1;
    pvtIndex[2] = 12;
    pvtIndex[3] = 0;
    pvtIndex[4] = 3;
    pvtIndex[5] = 2;
    pvtIndex[6] = 5;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(2074);
    pvt->generatePivots(sample, df, 2, 500);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 13;
    pvtIndex[1] = 10;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(30);
    pvt->generatePivots(sample, df, 5, 500);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 12;
    pvtIndex[1] = 1;
    pvtIndex[2] = 0;
    pvtIndex[3] = 4;
    pvtIndex[4] = 13;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(158);
    pvt->generatePivots(sample, df, 7, 500);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 7;
    pvtIndex[1] = 10;
    pvtIndex[2] = 16;
    pvtIndex[3] = 18;
    pvtIndex[4] = 8;
    pvtIndex[5] = 13;
    pvtIndex[6] = 5;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestKmedoids::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(602);
    pvt->generatePivots(sample,df,2,500);
    pvt->saveToFile("../testPivot.dat");

    KmedoidsPivots* test = new KmedoidsPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestKmedoids::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(1413);
    pvt->generatePivots(sample,df,5,500);
    pvt->saveToFile("../testPivot.dat");

    KmedoidsPivots* test = new KmedoidsPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestKmedoids::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    KmedoidsPivots* pvt = new KmedoidsPivots();
    pvt->setSeed(158);
    pvt->generatePivots(sample,df,7,500);
    pvt->saveToFile("../testPivot.dat");

    KmedoidsPivots* test = new KmedoidsPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}
