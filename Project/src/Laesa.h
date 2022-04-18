#ifndef LAESA_H
#define LAESA_H

#include <Hermes.h>
#include <Pivots.h>
#include <Dataset.h>
#include <queue>
#include <vector>
#include <CompTuple.h>
#include "../index/Index.h"

class Laesa: public Index
{

    private:

        //Trocar sample para dataset
        //Serializar dataset -> dentro da classe Dataset
        //laesa_dataset_raw_oid
        //-----
        //Fazer getter e setter
        size_t cardinality;
        size_t pivotSerializedSize;
        size_t nPivots;
        //-----
        DistanceFunction<Instance>* df;
        //Serializar estrutura -> laesa_dataset_idx_oid
        //-----
        Pivot* pivot;
        double** laesaMatrix;

    private:
        void destroyLaesa();

    public:

        Laesa();
        Laesa(Dataset* sample, DistanceFunction<Instance>* function, Pivot* pivot);
        ~Laesa();

        void setPivots(Pivot* pivot);
        void setNumberOfPivots(const size_t value);
        void setSeed(size_t seed);
        void setCardinality(size_t value);
        void setPivot(Pivot* pivot);
        void setLaesaMatrix(double** matrix);
        void setDistanceFunction(DistanceFunction<Instance>* df);

        size_t getNumberOfPivots() const;
        Instance* getPivot(size_t pos);
        u_int32_t getDistCount() const;
        size_t getCardinality() const;
        size_t getSerializedSize() const;
        Pivot* getPivot();
        double** getLaesaMatrix();
        DistanceFunction<Instance>* getDistanceFunction();

        void generatePivots(Dataset* sample);
        void computeDistanceMatrix(Dataset* sample);
        std::pair<size_t, double>* knn(Dataset* sample, Instance* query, size_t k);
        std::pair<size_t, double>* knnShapiro(Dataset* sample, Instance* query, size_t k);

        bool isEqual(Laesa* other);

        char* serialize();
        void unserialize(char* dataIn);

        void saveToFile(std::string fileName);
        void loadFromFile(std::string fileName);


        //Index
        size_t getDiskAccess();
        size_t getDistanceCount();
        void knn(Dataset* train, Instance* query, size_t k, std::vector<PairResult> & ans);

};

#endif // LAESA_H
