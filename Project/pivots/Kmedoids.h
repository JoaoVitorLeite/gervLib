#ifndef KMEDOIDS_H
#define KMEDOIDS_H

#include <Cluster.h>
#include <Dataset.h>
#include <Hermes.h>

class Kmedoids
{

    private:

        size_t nClusters, iterations, seed;
        Cluster** clusters;

    private:
        void initializeClusters(Dataset* sample);
        void reCenter(DistanceFunction<Instance>* df);
        void assignment(Dataset* sample, DistanceFunction<Instance>* df);


    public:

        //Constructors and destructors
        Kmedoids();
        ~Kmedoids();

        //Setters
        void setNumberOfClusters(size_t nClusters);
        void setSeed(size_t seed);
        void setNumberOfIterations(size_t iterations);

        //Getters
        size_t getSeed();
        size_t getNumberOfClusters() const;
        size_t getNumberOfIterations();
        Instance** getMedoids();
        Cluster* getCluster(size_t pos);

        //Public methods
        void run(Dataset* sample, DistanceFunction<Instance>* df, size_t nClusters);

};

#endif // KMEDOIDS_H
