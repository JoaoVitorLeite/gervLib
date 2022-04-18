#include "TestCompTuple.h"

void TestCompTuple::initTestCase()
{


}


void TestCompTuple::cleanupTestCase()
{


}


void TestCompTuple::test1()
{

    auto a = std::make_tuple(10,61);
    auto b = std::make_tuple(90,45);
    LessTuple<0,int,int> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test2()
{

    auto a = std::make_tuple(51.24,19.69,13.60);
    auto b = std::make_tuple(12.22,57.9,76.41);
    GreaterTuple<1,double,double,double> l;
    QCOMPARE(l.operator()(a,b), false);

}


void TestCompTuple::test3()
{

    auto a = std::make_tuple(88,44.76,46,3.4);
    auto b = std::make_tuple(60,76.53,46,22.70);
    LessTuple<2,int,double,int,double> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test4()
{

    auto a = std::make_tuple(35,98);
    auto b = std::make_tuple(41,89);
    GreaterTuple<0,int,int> l;
    QCOMPARE(l.operator()(a,b), false);

}


void TestCompTuple::test5()
{

    auto a = std::make_tuple(76.61,23.13,81.47);
    auto b = std::make_tuple(44.18,71.9,80.77);
    LessTuple<1,double,double,double> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test6()
{

    auto a = std::make_tuple(76,77.28,38,74.44);
    auto b = std::make_tuple(15,92.97,38,51.44);
    GreaterTuple<2,int,double,int,double> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test7()
{

    auto a = std::make_tuple(6,87);
    auto b = std::make_tuple(98,9);
    LessTuple<0,int,int> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test8()
{

    auto a = std::make_tuple(84.9,98.13,54.21);
    auto b = std::make_tuple(47.22,96.36,57.52);
    GreaterTuple<1,double,double,double> l;
    QCOMPARE(l.operator()(a,b), true);

}


void TestCompTuple::test9()
{

    auto a = std::make_tuple(40,75.42,22,62.59);
    auto b = std::make_tuple(92,66.57,22,11.28);
    LessTuple<2,int,double,int,double> l;
    QCOMPARE(l.operator()(a,b), false);

}

