#include "TestRandom.h"


void TestRandom::initTestCase()
{

}


void TestRandom::cleanupTestCase()
{


}


void TestRandom::test1()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(207);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 8;
    pvtIndex[1] = 5;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test2()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(13);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 2;
    pvtIndex[1] = 4;
    pvtIndex[2] = 9;
    pvtIndex[3] = 1;
    pvtIndex[4] = 0;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test3()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(10341);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 0;
    pvtIndex[1] = 4;
    pvtIndex[2] = 8;
    pvtIndex[3] = 1;
    pvtIndex[4] = 2;
    pvtIndex[5] = 3;
    pvtIndex[6] = 7;


    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test4()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(35);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 3;
    pvtIndex[1] = 14;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test5()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(7);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 5;
    pvtIndex[1] = 1;
    pvtIndex[2] = 14;
    pvtIndex[3] = 9;
    pvtIndex[4] = 12;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test6()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(183);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 12;
    pvtIndex[1] = 9;
    pvtIndex[2] = 14;
    pvtIndex[3] = 8;
    pvtIndex[4] = 13;
    pvtIndex[5] = 0;
    pvtIndex[6] = 7;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test7()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(40);
    pvt->generatePivots(sample, df,2);

    size_t* pvtIndex = new size_t[2];
    pvtIndex[0] = 9;
    pvtIndex[1] = 6;

    for(size_t x = 0; x < 2; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test8()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(1441);
    pvt->generatePivots(sample, df,5);

    size_t* pvtIndex = new size_t[5];
    pvtIndex[0] = 6;
    pvtIndex[1] = 19;
    pvtIndex[2] = 7;
    pvtIndex[3] = 4;
    pvtIndex[4] = 12;

    for(size_t x = 0; x < 5; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test9()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(1);
    pvt->generatePivots(sample, df,7);

    size_t* pvtIndex = new size_t[7];
    pvtIndex[0] = 9;
    pvtIndex[1] = 12;
    pvtIndex[2] = 13;
    pvtIndex[3] = 15;
    pvtIndex[4] = 17;
    pvtIndex[5] = 6;
    pvtIndex[6] = 3;

    for(size_t x = 0; x < 7; x++)
    {

        QCOMPARE(pvt->getPivot(x)->getOID(), pvtIndex[x]);

    }

    delete (sample);
    delete (df);
    delete [] (pvtIndex);

}


void TestRandom::test10()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset1.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(207);
    pvt->generatePivots(sample, df,2);
    pvt->saveToFile("../testPivot.dat");

    RandomPivots* test = new RandomPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestRandom::test11()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(7);
    pvt->generatePivots(sample, df,5);
    pvt->saveToFile("../testPivot.dat");

    RandomPivots* test = new RandomPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}


void TestRandom::test12()
{

    Dataset* sample = new Dataset("/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset3.csv", ",");
    DistanceFunction<Instance>* df = new EuclideanDistance<Instance>();
    RandomPivots* pvt = new RandomPivots();
    pvt->setSeed(1);
    pvt->generatePivots(sample, df,7);
    pvt->saveToFile("../testPivot.dat");

    RandomPivots* test = new RandomPivots();
    test->loadFromFile("../testPivot.dat");

    QCOMPARE(pvt->isEqual(test), true);

    delete (sample);
    delete (df);

}

