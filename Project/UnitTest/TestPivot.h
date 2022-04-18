#ifndef TESTPIVOT_H
#define TESTPIVOT_H

#include <QtTest>
#include <Dataset.h>
#include <Hermes.h>

class TestPivot : public QObject
{
    Q_OBJECT

private slots:

    void initTestCase();
    void cleanupTestCase();
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();
    void test6();

private:
    Dataset* sample;
    DistanceFunction<Instance>* df;

};

#endif // TESTPIVOT_H
