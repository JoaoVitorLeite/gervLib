#ifndef TESTLAESA_H
#define TESTLAESA_H

#include <QtTest>
#include <Dataset.h>
#include <Hermes.h>
#include <Laesa.h>
#include <Pivots.h>

class TestLaesa : public QObject
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
    void test7();
    void test8();
    void test9();
    void test10();
    void test11();
    void test12();

};

#endif // TESTLAESA_H