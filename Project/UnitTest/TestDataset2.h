#ifndef TESTDATASET2_H
#define TESTDATASET2_H

#include <QtTest>
#include <Dataset.h>

class TestDataset2 : public QObject
{
    Q_OBJECT

private:
    std::string pathWithSpace, pathWithComma;

    Dataset* dataset;

private slots:

    void initTestCase();
    void cleanupTestCase();
    //void init();
    //void cleanup();
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();
    void test7();

};

#endif // TESTDATASET2_H
