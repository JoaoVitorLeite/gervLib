#include "Cluster.h"


Cluster::Cluster()
{

    medoid = nullptr;
    set = std::vector<Instance*>();

}


Cluster::Cluster(Instance* medoid)
{

    this->medoid = medoid;
    set = std::vector<Instance*>();

}


Cluster::~Cluster()
{

    clearSet();

}


void Cluster::setMedoid(Instance *medoid)
{

    this->medoid = medoid;

}


void Cluster::setSet(std::vector<Instance *> vec)
{

    this->set = vec;

}


Instance* Cluster::getInstance(size_t pos)
{

    Instance* aux = nullptr;

    if(pos >= set.size())
        throw std::invalid_argument("Index Out of Bound !_!");
    else
        aux = set[pos];

    return aux;

}


Instance* Cluster::getMedoid()
{

    return medoid;

}


size_t Cluster::size()
{

    return set.size();

}


void Cluster::addInstance(Instance *inst)
{

    set.push_back(inst);

}


void Cluster::clearSet()
{

    set.clear();

}


void Cluster::printCluster()
{

    std::cout << "Medoid = " << medoid->toStringWithOID() << std::endl;
    for(Instance* aux : this->set)
        std::cout << aux->toStringWithOID() << std::endl;

}

