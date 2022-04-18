#ifndef PIVOT_H
#define PIVOT_H

#include <Dataset.h>
#include <limits.h>
#include <Util.h>
#include <Hermes.h>

enum PIVOT_TYPE{RANDOM, GNAT, CONVEX, KMEDOIDS, MAXSEPARETED, MAXVARIANCE, SELECTION, PCA, SSS};

//Descrição da Classe
class Pivot{

    //Private properties
    private:
        size_t currentPivot;
        size_t seed;
        size_t nPivots;
        size_t instanceSize;
        PIVOT_TYPE pivotType;
        Instance **pivots;

    //Private functions
    private:
        void clearPivots();
        void setInstanceSize();

    //Public functions
    public:
        //Constructors and destructors
        Pivot();
        virtual ~Pivot();

        //Public metods
        Instance* getNextPivot();

        //Setters
        void setNumberOfPivots(const size_t &value);
        void setSeed(const size_t &seed);
        void setPivot(Instance *value, const size_t &pos);
        void setPivots(Instance **value);
        void setPivotType(PIVOT_TYPE pvtType);

        //Getters
        size_t getNumberOfPivots() const;
        size_t getSeed() const;
        Instance *getPivot(size_t pos) const;
        Instance **getPivots() const;
        PIVOT_TYPE getPivotType() const;
        size_t getSerializedSize();

        //Métodos virtuais públicos
        virtual void generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots) = 0;

        bool isEqual(Pivot* pivot);

        char* serialize();
        void unserialize(char* dataIn);

        void saveToFile(std::string fileName);
        void loadFromFile(std::string fileName);

};

#endif // PIVOT_H
