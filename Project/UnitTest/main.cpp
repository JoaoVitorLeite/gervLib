#include <iostream>
#include <Test-Includes.h>
#include <QtTest>

void doubleLines()
{

    std::cout << "\n\n";

}

int main(int argc, char *argv[])
{

    int status = 0;

    {
        doubleLines();
        TestDataset1 t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestDataset2 t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestDataset3 t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestRandom t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestConvex t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestGnat t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestKmedoids t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestMaxSepareted t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestMaxVariance t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestPCA t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestSelection t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestSSS t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestSequentialScan t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestLaesa t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }

    {
        doubleLines();
        TestCompTuple t;
        status |= QTest::qExec(&t, argc, argv);
        doubleLines();
    }


    return status;
}
