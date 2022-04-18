QT -= gui
QT += testlib


CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../utils/Dataset.cpp \
        ../utils/Util.cpp \
        ParserArguments.cpp \
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
        SequentialScan.cpp \
        Laesa.cpp \
#        query.cpp
#        mainIntrinsicDimensionality.cpp

HEADERS += \
        ../distanceBrowsing/DistanceBrowsing.h \
        ../hermes/MatusitaDistance.h \
        ../hermes/MatusitaDistance-inl.h \
        ../hermes/CosineDistance-inl.h \
        ../hermes/CosineDistance.h \
        ../hermes/Hermes.h \
        ../hermes/TanimotoDistance-inl.h \
        ../hermes/TanimotoDistance.h \
        ../index/Index.h \
        ../kdtree/DirectoryNode.h \
        ../kdtree/KdTree.h \
        ../kdtree/LeafNode.h \
        ../kdtree/Node.h \
        ../omni/OmniKdTree.h \
        ../utils/BasicArrayObject.h \
        ../utils/Dataset.h \
        ../utils/Util.h \
        ParserArguments.h \
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
        CompTuple.h \
        ../pivots/SelectionPivots.h \
        ../pivots/SSSPivots.h \
        ../pivots/PCAPivots.h \
        SequentialScan.h \
        Laesa.h \
        ../hermes/EuclideanDistance.h \
        ../hermes/EuclideanDistance-inl.h

        #CompTuple-inl.h \ # -> Implementation of CompTuple.h


TRANSLATIONS += \
    ProjectJoao_en_US.ts

INCLUDEPATH += ../utils \
               ../hermes \
               ../src/ \
               ../pivots/ \
               ../index/ \
               ../kdtree/ \
               ../distanceBrowsing/ \
               ../omni/ \

INCLUDEPATH += ../eigen #Eigen 3.3.9


DISTFILES += \
    ../datasets/open1/Dataset1.csv \
    ../datasets/open1/Dataset2.csv \
    ../datasets/open1/Dataset3.csv \
    ../datasets/open2/Dataset1.csv \
    ../datasets/open2/Dataset2.csv \
    ../datasets/open2/Dataset3.csv \
    ../hermes/gervLib.cflags \
    ../hermes/gervLib.cxxflags
