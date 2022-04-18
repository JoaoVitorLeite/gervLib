#ifndef TESTDATASET1_H
#define TESTDATASET1_H

#include <QtTest>
#include <Dataset.h>

class TestDataset1 : public QObject
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

#endif // TESTDATASET1_H
