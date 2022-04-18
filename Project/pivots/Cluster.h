#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <BasicArrayObject.h>

class Cluster
{

    private:

        Instance* medoid; //Medoid
        std::vector<Instance*> set; //Set of elements inside the cluster(Medoid is also included)

    public:

        //Constructors and destructor
        Cluster();
        Cluster(Instance* medoid);
        ~Cluster();

        //Setters
        void setMedoid(Instance* medoid);
        void setSet(std::vector<Instance*> vec);

        //Getters
        Instance* getInstance(size_t pos);
        Instance* getMedoid();
        size_t size();

        //Public method
        void addInstance(Instance* inst);
        void clearSet();

        //Print
        void printCluster();

};

#endif // CLUSTER_H
