#include "Pivot.h"


void Pivot::clearPivots()
{

    if(pivots != nullptr)
    {

        for(size_t x = 0; x < getNumberOfPivots(); x++)
            delete (pivots[x]);

        delete[] pivots;

    }

}


void Pivot::setInstanceSize()
{

    instanceSize = getPivot(0)->getSerializedSize();

}


Pivot::Pivot()
{

    this->currentPivot = 0;
    this->nPivots = 0;
    this->pivotType = PIVOT_TYPE::RANDOM;
    this->pivots = nullptr;
    this->seed = 0;

}


Pivot::~Pivot()
{

    clearPivots();

}


Instance* Pivot::getNextPivot()
{

    Instance *ans = nullptr;

    if(currentPivot >= getNumberOfPivots())
    {

        throw std::invalid_argument("No more pivots !_!");

    }
    else
    {

        ans = getPivot(currentPivot);
        currentPivot++;

    }

    return ans;

}


void Pivot::setNumberOfPivots(const size_t &value)
{

    nPivots = value;
    clearPivots();
    pivots = new Instance*[nPivots];

}


void Pivot::setSeed(const size_t &seed)
{

    this->seed = seed;

}


void Pivot::setPivot(Instance *value, const size_t &pos)
{

    if(pos < getNumberOfPivots())
    {
        //Criando uma nova região de memória cujo valor é copiado de value
        pivots[pos] = new Instance(*value);
        //pivots[pos] = value;

    }
    else
    {

        throw std::invalid_argument("Out of bounds pivot position !_!");

    }

}


void Pivot::setPivots(Instance **value)
{

    pivots = value;

}


void Pivot::setPivotType(PIVOT_TYPE pvtType)
{

    pivotType = pvtType;

}


size_t Pivot::getNumberOfPivots() const
{

    return nPivots;

}


size_t Pivot::getSeed() const
{

    return seed;

}


Instance* Pivot::getPivot(size_t pos) const
{

    Instance *ans = nullptr;

    if(pos >= getNumberOfPivots())
    {

        throw std::invalid_argument("Invalid pivot !_!");

    }
    else
    {

        ans = pivots[pos];

    }

    return ans;

}


Instance** Pivot::getPivots() const
{

    return pivots;

}

PIVOT_TYPE Pivot::getPivotType() const
{

    return pivotType;

}


size_t Pivot::getSerializedSize()
{

    setInstanceSize();
    return (4*sizeof(size_t) + sizeof(PIVOT_TYPE) + instanceSize*getNumberOfPivots());

}


bool Pivot::isEqual(Pivot *pivot)
{

    bool answer = true;

    if((getNumberOfPivots() != pivot->getNumberOfPivots()) || (getPivotType() != pivot->getPivotType()))
        answer = false;
    else
    {

        for(size_t x = 0; x < getNumberOfPivots(); x++)
        {

            if(!getPivot(x)->isEqual(pivot->getPivot(x)))
            {

                answer = false;
                break;

            }


        }

    }

    return answer;

}


char* Pivot::serialize()
{

    /*
    nPivots
    seed
    Dimensionality
    InstanceSize
    PivotType
    Instance**
    */

    setInstanceSize();
    char* serialized = new char[getSerializedSize()];
    size_t aux = getPivot(0)->getSize();
    size_t size = getNumberOfPivots();

    memcpy(serialized, &nPivots, sizeof(size_t));
    memcpy(serialized + sizeof(size_t), &seed, sizeof(size_t));
    memcpy(serialized + sizeof(size_t)*2, &aux, sizeof(size_t));
    memcpy(serialized + sizeof(size_t)*3, &instanceSize, sizeof(size_t));
    memcpy(serialized + sizeof(size_t)*4, &pivotType, sizeof(PIVOT_TYPE));

    for(size_t x = 0; x < size; x++)
    {

        memcpy(serialized + sizeof(size_t)*4 + sizeof(PIVOT_TYPE) + instanceSize*x, getPivot(x)->serialize(), instanceSize);

    }

    return serialized;

}


void Pivot::unserialize(char* dataIn)
{

    size_t dimensionality;

    memcpy(&nPivots, dataIn, sizeof(size_t));
    memcpy(&seed, dataIn + sizeof(size_t), sizeof(size_t));
    memcpy(&dimensionality, dataIn + sizeof(size_t)*2, sizeof(size_t));
    memcpy(&instanceSize, dataIn + sizeof(size_t)*3, sizeof(size_t));
    memcpy(&pivotType, dataIn + sizeof(size_t)*4, sizeof(PIVOT_TYPE));

    char* aux = new char[instanceSize];

    setNumberOfPivots(nPivots);
    for(size_t x = 0; x < getNumberOfPivots(); x++)
        pivots[x] = new Instance(x, dimensionality);

    for(size_t x = 0; x < getNumberOfPivots(); x++)
    {

        memcpy(aux, dataIn + sizeof(size_t)*4 + sizeof(PIVOT_TYPE) + instanceSize*x, instanceSize);
        pivots[x]->unserialize(aux);

    }

    delete [] aux;
}


void Pivot::saveToFile(std::string fileName)
{

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    char* ans = serialize();

    file.write(ans, getSerializedSize());
    file.close();

}


void Pivot::loadFromFile(std::string fileName)
{

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    char* aux = new char[4*sizeof(size_t) + sizeof(PIVOT_TYPE)];
    file.read(aux, 4*sizeof(size_t) + sizeof(PIVOT_TYPE));

    size_t dimensionality;

    memcpy(&nPivots, aux, sizeof(size_t));
    memcpy(&seed, aux + sizeof(size_t), sizeof(size_t));
    memcpy(&dimensionality, aux + sizeof(size_t)*2, sizeof(size_t));
    memcpy(&instanceSize, aux + sizeof(size_t)*3, sizeof(size_t));
    memcpy(&pivotType, aux + sizeof(size_t)*4, sizeof(PIVOT_TYPE));

    setNumberOfPivots(nPivots);
    for(size_t x = 0; x < getNumberOfPivots(); x++) pivots[x] = new Instance(x, dimensionality);

    file.seekg(0);
    char* ans = new char[getSerializedSize()];
    file.read(ans, getSerializedSize());

    unserialize(ans);

    file.close();

    delete [] (aux);
    delete [] (ans);

}

