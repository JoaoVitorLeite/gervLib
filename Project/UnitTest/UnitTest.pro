QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
        ../utils/Dataset.cpp \
        ../utils/Util.cpp \
        main.cpp \
        ../pivots/Pivot.cpp \
        ../pivots/RandomPivots.cpp \
        ../pivots/ConvexPivots.cpp \
        ../pivots/GnatPivots.cpp \
        ../pivots/Kmedoids.cpp \
        ../pivots/Cluster.cpp \
        ../pivots/KmedoidsPivots.cpp \
        ../pivots/MaxSeparetedPivots.cpp \
        ../pivots/MaxVariancePivots.cpp \
        ../pivots/SelectionPivots.cpp \
        ../pivots/SSSPivots.cpp \
        ../pivots/PCAPivots.cpp \
        ../src/SequentialScan.cpp \
        ../src/Laesa.cpp \
        TestCompTuple.cpp \
        TestConvex.cpp \
        TestDataset1.cpp \
        TestDataset2.cpp \
        TestDataset3.cpp \
        TestGnat.cpp \
        TestKmedoids.cpp \
        TestMaxSepareted.cpp \
        TestMaxVariance.cpp \
        TestPCA.cpp \
        TestRandom.cpp \
        TestSSS.cpp \
        TestSelection.cpp \
        TestSequentialScan.cpp \
        TestLaesa.cpp \

HEADERS += \
        ../hermes/Hermes.h \
        ../utils/BasicArrayObject.h \
        ../utils/Dataset.h \
        ../utils/Util.h \
        ../pivots/Pivot.h \
        ../pivots/Pivots.h \
        ../pivots/RandomPivots.h \
        ../pivots/ConvexPivots.h \
        ../pivots/GnatPivots.h \
        ../pivots/Kmedoids.h \
        ../pivots/Cluster.h \
        ../pivots/KmedoidsPivots.h \
        ../pivots/MaxSeparetedPivots.h \
        ../pivots/MaxVariancePivots.h \
        ../src/CompTuple.h \
        ../pivots/SelectionPivots.h \
        ../pivots/SSSPivots.h \
        ../pivots/PCAPivots.h \
        ../src/SequentialScan.h \
        ../src/Laesa.h \
        TestCompTuple.h \
        TestConvex.h \
        TestDataset1.h \
        TestDataset2.h \
        TestDataset3.h \
        Test-Includes.h \
        TestGnat.h \
        TestKmedoids.h \
        TestMaxSepareted.h \
        TestMaxVariance.h \
        TestPCA.h \
        TestRandom.h \
        TestSSS.h \
        TestSelection.h \
        TestSequentialScan.h \
        TestLaesa.h \

        #CompTuple-inl.h \ # -> Implementation of CompTuple.h

INCLUDEPATH += ../utils/ \
               ../hermes/ \
               ../src/ \
               ../pivots/ \
               ../eigen/ \
