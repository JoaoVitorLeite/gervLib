#include "TestDataset2.h"


void TestDataset2::initTestCase()
{

    pathWithSpace = "/home/joaovictor/Documents/IC/gervLib/Project/datasets/open1/Dataset2.csv";
    pathWithComma = "/home/joaovictor/Documents/IC/gervLib/Project/datasets/open2/Dataset2.csv";
    Dataset* otherConstructor = new Dataset(pathWithSpace,15,3);
    dataset = new Dataset(pathWithComma, ",");

    delete (otherConstructor);
}


void TestDataset2::cleanupTestCase()
{

    delete (dataset);

}


void TestDataset2::test1()
{

    Instance aux = Instance(2,3);
    aux.set(0,7.0);
    aux.set(1,13.0);
    aux.set(2,17.0);

    size_t validPos = 2, invalidPos = 200;

    QCOMPARE(aux.isEqual(&(*dataset)[validPos]), true);

    QVERIFY_EXCEPTION_THROWN((*dataset)[invalidPos], std::invalid_argument);

}


void TestDataset2::test2()
{

    Dataset* dataSpace = new Dataset(pathWithSpace,15,3);

    QCOMPARE((*dataset) == (dataSpace), true);

    delete(dataSpace);

}


void TestDataset2::test3()
{

    Dataset* data = new Dataset(pathWithComma, ",");

    bool* bitmap = new bool[data->getCardinality()];

    for(size_t x = 0; x < data->getCardinality(); x++)
        bitmap[x] = false;

    Instance** aux = data->sample(5, false);

    for(size_t x = 0; x < 5; x++)
    {

        if(!bitmap[aux[x]->getOID()])
            bitmap[aux[x]->getOID()] = true;
        else
            QFAIL("Repetition not allowed !_!");

    }

    aux = nullptr;

    delete [] (bitmap);
    delete [] (aux);
    delete (data);

}


void TestDataset2::test4()
{

    Dataset* data = new Dataset(pathWithComma, ",");
    std::tuple<Instance**, Instance**, size_t, size_t> split = data->splitTrainTest(0.8,0.2);
    bool* bitmap = new bool[data->getCardinality()];
    Instance* inst = nullptr;

    for(size_t x = 0; x < data->getCardinality(); x++)
        bitmap[x] = false;

    for(size_t x = 0; x < std::get<2>(split); x++)
    {

        inst = std::get<0>(split)[x];

        if(!bitmap[inst->getOID()])
            bitmap[inst->getOID()] = true;
        else
            QFAIL("Repetition not allowed !_!");

    }

    for(size_t x = 0; x < std::get<3>(split); x++)
    {

        inst = std::get<1>(split)[x];

        if(!bitmap[inst->getOID()])
            bitmap[inst->getOID()] = true;
        else
            QFAIL("Repetition not allowed !_!");

    }

    inst = nullptr;

    std::get<0>(split) = nullptr;
    std::get<1>(split) = nullptr;

    delete [] (bitmap);
    delete (inst);
    delete (data);

}


void TestDataset2::test5()
{

    Dataset* data = new Dataset(pathWithComma, ",");
    bool* bitmap = new bool[data->getCardinality()];

    for(size_t x = 0; x < data->getCardinality(); x++)
    {

        bitmap[x] = false;

    }

    data->shuffle();

    for(size_t x = 0; x < data->getCardinality(); x++)
    {

        if(!bitmap[data->instance(x)->getOID()])
            bitmap[data->instance(x)->getOID()] = true;
        else
            QFAIL("Repetition in shuffle !_! ");

    }

    delete [] (bitmap);
    delete (data);

}


void TestDataset2::test6()
{

    Dataset* data = new Dataset(pathWithComma, ",");

    QCOMPARE(dataset->isEqual(data), true);

    delete (data);

}


void TestDataset2::test7()
{

    Dataset* data = new Dataset(pathWithComma, ",");

    data->saveToFile("../testDataset2.dat");

    Dataset* t = new Dataset();

    t->loadFromFile("../testDataset2.dat");

    QCOMPARE(data->isEqual(t), true);

}

