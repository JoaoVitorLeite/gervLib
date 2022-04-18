#ifndef DATASET_H
#define DATASET_H

#include <cstring>
#include <fstream>
#include <BasicArrayObject.h>
#include <regex>
#include <vector>
#include <Util.h>
#include <Hermes.h>

class Dataset{

    private:
        Instance **data;
        size_t cardinality;
        size_t dimensionality;
        size_t seed;
        size_t instanceSize;

    private:
        void destroyData();
        void openDataset(std::string filePath);
        void openDataset(std::string filePath, std::string separator);
        std::vector<double> split(std::string str, std::string delimiter);
        size_t serializedSize();

    public:
        //Constructors and Destructors
        Dataset();
        Dataset(std::string filePath, size_t cardinality, size_t dimensionality); //-
        Dataset(Instance** elements, size_t cardinality, size_t dimensionality); //-
        Dataset(std::string filePath, std::string separator);
        ~Dataset(); //-

        //Operator Overloading
        Instance& operator[](size_t pos); //Reatribuição permitida
        const Instance& operator[](size_t pos) const; //Reatribuição não permitida //-
        bool operator==(Dataset* other); //-

        //Setters
        void setInstance(Instance *instance, const size_t &pos); //-
        void setSeed(const size_t &seed); //-
        void setCardinality(const size_t &value); //-
        void setDimensionality(const size_t &value);
        void setInstanceSize();

        //Getters
        Instance* instance(size_t pos);
        Instance* getInstance(size_t pos);
        Instance** getElements();
        size_t getDimensionality() const;
        size_t getCardinality() const;
        size_t getSeed() const;
        size_t getSerializedSize();

        //Public Methods
        Instance** sample(size_t size, bool reposition);
        Instance** sample(size_t size, bool reposition, size_t seed);
        std::tuple<Instance**, Instance**, size_t, size_t> splitTrainTest(double train, double test);
        std::tuple<Instance**, Instance**, size_t, size_t> splitTrainTest(double train, double test, size_t seed);
        void swap(size_t pos1, size_t pos2); //Pode ser private
        void shuffle();
        void shuffle(size_t seed);
        void normalize();
        bool isEqual(Dataset* other);
        void saveDataset(std::string path, std::string separator = ",");
        size_t intrinsicDimensionality(DistanceFunction<Instance>* df, size_t sampleSize);

        //Print
        void printDataset();

        char* serialize();
        void unserialize(char* dataIn);

        void saveToFile(std::string fileName);
        void loadFromFile(std::string fileName/*, size_t dimensionality, size_t cardinality*/);

};

#endif // DATASET_H
