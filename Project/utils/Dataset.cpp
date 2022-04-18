#include "Dataset.h"

void Dataset::destroyData(){

    if (data != nullptr){
        for(size_t x = 0; x < getCardinality(); x++){
            if(data[x] != nullptr)
                delete (data[x]);
        }
        delete[] data;
    }
}

void Dataset::openDataset(std::string filePath)
{

    std::ifstream file(filePath);
    double aux;
    Instance* inst;

    for (size_t x = 0; x < getCardinality(); x++)
    {

        inst = new Instance(x, getDimensionality());

        for (size_t y = 0; y < getDimensionality(); y++)
        {

            file >> aux;
            inst->set(y, aux);

        }

        data[x] = inst;

    }

    inst = nullptr;
    delete inst;

    file.close();

}


void Dataset::openDataset(std::string filePath, std::string separator)
{

    std::string first, line;
    double aux;

    std::ifstream myFile;
    myFile.open(filePath);

    std::getline(myFile, first);

    std::vector<double> auxFirst = split(first, separator);
    std::vector<std::vector<double>> auxData;
    dimensionality = auxFirst.size();

    Instance *inst;

    auxData.push_back(auxFirst);

    while(std::getline(myFile, line))
    {

        auxData.push_back(split(line, separator));

    }

    cardinality = auxData.size();

    data = new Instance*[getCardinality()];

    for (size_t x = 0; x < getCardinality(); x++)
    {

        inst = new Instance(x, getDimensionality());

        for (size_t y = 0; y < getDimensionality(); y++)
        {

            aux = auxData[x][y];
            inst->set(y, aux);

        }

        data[x] = inst;

    }

    for(std::vector<double> v : auxData)
        v.clear();

    auxData.clear();

    inst = nullptr;
    delete inst;

    myFile.close();

}


std::vector<double> Dataset::split(std::string str, std::string delimiter="[//s+,;]")
{

    std::regex rgx(delimiter);
    std::sregex_token_iterator iter(str.begin(),str.end(),rgx,-1);
    std::sregex_token_iterator end;
    std::vector<double> v;
    double d;

    for(; iter != end; ++iter)
    {

        d = stod(*iter);
        v.push_back(d);

    }

    return v;

}



size_t Dataset::serializedSize()
{

    return (4*sizeof(size_t) + instanceSize*getCardinality());
}



Dataset::Dataset(){

    data = nullptr;
    setCardinality(0);
    setDimensionality(0);
    setSeed(0);
}

Dataset::Dataset(std::string filePath, size_t cardinality, size_t dimensionality)
{

    seed = 0;
    this->cardinality = cardinality;
    this->dimensionality = dimensionality;
    data = new Instance*[getCardinality()];

    for (size_t x = 0; x < getCardinality(); x++)
    {

        data[x] = new Instance[getDimensionality()];

    }

    openDataset(filePath);

}


Dataset::Dataset(Instance** elements, size_t cardinality, size_t dimensionality)
{

    seed = 0;
    this->cardinality = cardinality;
    this->dimensionality = dimensionality;
    data = elements;

}


Dataset::Dataset(std::string filePath, std::string separator)
{

    data = nullptr;
    cardinality = dimensionality = 0;
    openDataset(filePath, separator);

}


Dataset::~Dataset(){

    destroyData();
}


Instance& Dataset::operator[](size_t pos)
{
    Instance* ans = nullptr;

    if(pos < getCardinality())
    {

        ans = data[pos];

    }
    else
    {

        throw std::invalid_argument("Out of Bound Exception !_!");

    }

    return *ans;
}


const Instance& Dataset::operator[](size_t pos) const
{
    Instance* ans = nullptr;

    if(pos < getCardinality())
    {

        ans = data[pos];

    }
    else
    {

        throw std::invalid_argument("Out of Bound Exception !_!");

    }

    return *ans;
}


bool Dataset::operator==(Dataset* other)
{

    return isEqual(other);

}


void Dataset::setInstance(Instance *instance, const size_t &pos){

    if(pos < getCardinality())
    {

        data[pos] = instance;

    }
    else
    {

        throw std::invalid_argument("Out of Bound Exception !_!");

    }

}


void Dataset::setSeed(const size_t &seed)
{

    this->seed = seed;

}


void Dataset::setCardinality(const size_t &value)
{

    cardinality = value;

}


void Dataset::setDimensionality(const size_t &value)
{

    dimensionality = value;

}


void Dataset::setInstanceSize()
{

    instanceSize = instance(0)->getSerializedSize();

}


Instance* Dataset::instance(size_t pos)
{

    Instance* ans = nullptr;

    if(pos < getCardinality())
    {

        ans = data[pos];

    }
    else
    {

        throw std::invalid_argument("Out of Bound Exception !_!");

    }

    return ans;

}


Instance* Dataset::getInstance(size_t pos)
{

    Instance* ans = nullptr;

    if(pos < getCardinality())
    {

        ans = data[pos];

    }
    else
    {

        throw std::invalid_argument("Out of Bound Exception !_!");

    }

    return ans;

}


Instance** Dataset::getElements()
{

    return data;

}


size_t Dataset::getDimensionality() const
{

    return dimensionality;

}


size_t Dataset::getCardinality() const
{

    return cardinality;

}


size_t Dataset::getSeed() const
{

    return seed;

}

size_t Dataset::getSerializedSize()
{

    setInstanceSize();
    return (4*sizeof(size_t) + instanceSize*getCardinality());

}

Instance** Dataset::sample(size_t size, bool reposition)
{

    Instance** ans = new Instance*[size];
    size_t* aux;

    if(reposition) aux = randomNumber(0, getCardinality(), size, getSeed());
    else aux = uniqueRandomNumber(0, getCardinality(), size, getSeed());

    for(size_t x = 0; x < size; x++)
        ans[x] = instance(aux[x]);

    delete[] aux;

    return ans;

}


Instance** Dataset::sample(size_t size, bool reposition, size_t seed)
{
    Instance** ans = new Instance*[size];
    size_t* aux;

    if(reposition) aux = randomNumber(0, getCardinality(), size, seed);
    else aux = uniqueRandomNumber(0, getCardinality(), size, seed);

    for(size_t x = 0; x < size; x++)
        ans[x] = instance(aux[x]);

    delete[] aux;

    return ans;
}


std::tuple<Instance**, Instance**, size_t, size_t> Dataset::splitTrainTest(double train, double test)
{

    size_t pos, sizeTrain = getCardinality() * train, sizeTest = std::max(getCardinality() - sizeTrain*1.0, getCardinality() * test);
    Instance** ansTrain = new Instance*[sizeTrain];
    Instance** ansTest = new Instance*[sizeTest];
    size_t* aux;

    aux = shuffleIndex(0, getCardinality(), getSeed());

    for(size_t x = 0; x < sizeTrain; x++)
        ansTrain[x] = instance(aux[x]);

    pos = 0;

    for(size_t y = sizeTrain; y < getCardinality(); y++)
        ansTest[pos++] = instance(aux[y]); //Pode ser trocado

    return std::make_tuple(ansTrain, ansTest, sizeTrain, sizeTest);
}


std::tuple<Instance**, Instance**, size_t, size_t> Dataset::splitTrainTest(double train, double test, size_t seed)
{

    size_t* aux;
    size_t pos, sizeTrain = getCardinality() * train, sizeTest = std::max(getCardinality() - sizeTrain*1.0, getCardinality() * test);
    Instance** ansTrain = new Instance*[sizeTrain];
    Instance** ansTest = new Instance*[sizeTest];

    aux = shuffleIndex(0, getCardinality(), seed);

    for(size_t x = 0; x < sizeTrain; x++)
        ansTrain[x] = instance(aux[x]);

    pos = 0;

    for(size_t y = sizeTrain; y < getCardinality(); y++)
        ansTest[pos++] = instance(aux[y]);

    return std::make_tuple(ansTrain, ansTest, sizeTrain, sizeTest);
}


void Dataset::swap(size_t pos1, size_t pos2)
{

    Instance* temp = instance(pos1);
    setInstance(instance(pos2), pos1);
    setInstance(temp, pos2);

}


void Dataset::shuffle()
{

    srand(getSeed());

    for(size_t z = getCardinality() - 1; z > 0; z--)
    {

        size_t aux = rand() % (z+1);
        swap(z, aux);

    }

}


void Dataset::shuffle(size_t seed)
{

    srand(seed);

    for(size_t z = getCardinality() - 1; z > 0; z--)
    {

        size_t aux = rand() % (z+1);
        swap(z, aux);

    }

}


void Dataset::normalize()
{

    double max, min, current, newValue;
    Instance* aux = nullptr;

    for(size_t col = 0; col < this->getDimensionality(); col++)
    {

        max = std::numeric_limits<double>::min(), min = std::numeric_limits<double>::max();

        for(size_t row = 0; row < getCardinality(); row++)
        {

            current = instance(row)->get(col);

            if(current > max) max = current;
            if(current < min) min = current;

        }

        for(size_t row = 0; row < this->getCardinality(); row++)
        {

            aux = instance(row);
            newValue = (aux->get(col) - min)/(max - min);
            aux->set(col, newValue);

        }

    }

    delete aux;

}


bool Dataset::isEqual(Dataset *other)
{

    bool equal = true;

    if((getCardinality() == other->getCardinality()) && (getDimensionality() == other->getDimensionality()))
    {

        for(size_t x = 0; x < getCardinality(); x++)
        {

            if(!(instance(x)->isEqual(other->instance(x))))
            {

                equal = false;
                break;

            }

        }

    }

    return equal;

}


void Dataset::saveDataset(std::string path, std::string separator)
{

    std::ofstream mFile(path);

    for(size_t x = 0; x < getCardinality(); x++)
    {

        mFile << instance(x)->toString(separator) << "\n";

    }

    mFile.close();

}


size_t Dataset::intrinsicDimensionality(DistanceFunction<Instance> *df, size_t sampleSize)
{

    Dataset* dataSample = new Dataset(sample(sampleSize, false, getSeed()), sampleSize, getDimensionality());
//    double length = (getCardinality()*(getCardinality()-1))/2.0, mean = 0, std = 0, dist;
    double length = (sampleSize*(sampleSize-1))/2.0, mean = 0, std = 0, dist;

    for(size_t x = 0; x < dataSample->getCardinality(); x++)
    {

        for(size_t y = x+1; y < dataSample->getCardinality(); y++)
        {

            mean += df->getDistance(*dataSample->instance(x), *dataSample->instance(y)) / length;

        }

    }

    for(size_t x = 0; x < dataSample->getCardinality(); x++)
    {

        for(size_t y = x+1; y < dataSample->getCardinality(); y++)
        {

            dist = df->getDistance(*dataSample->instance(x), *dataSample->instance(y)) / length;
            std = ((dist-mean)*(dist-mean))/(length-1);

        }

    }

    std = std::sqrt(std);

    size_t ans = std::ceil((mean*mean)/(2*std));

    delete (dataSample);

//    std::cout << "\nMEAN = " << mean << std::endl;
//    std::cout << "\nSTD = " << std << std::endl;
//    std::cout << "\nANS = " << (mean*mean)/(2*std) << std::endl;
//    std::cout << "\nANS = " << ans << std::endl;

    if(ans <= 2) return 2;
    else
    {

        if(ans < getDimensionality()) return ans;
        else return getDimensionality();

    }

}


void Dataset::printDataset(){

    Instance* aux = nullptr;

    for (size_t x = 0; x < getCardinality(); x++)
    {

        aux = data[x];

        std::cout << aux->getOID() << " ";

        for (size_t y = 0; y < aux->size(); y++)
            std::cout << (*aux)[y] << " ";

        std::cout << std::endl;

    }

    aux = nullptr;
    delete aux;

}


char* Dataset::serialize()
{

    //CARDINALITY
    //DIMENSIONALITY
    //SEED
    //INSTANCE SIZE

    setInstanceSize();
    char* dataOut = nullptr;

    if(dataOut == nullptr)
    {

        dataOut = new char[serializedSize()];
        size_t size = getCardinality();

        memcpy(dataOut, &cardinality, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t), &dimensionality, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t)*2, &seed, sizeof(size_t));
        memcpy(dataOut + sizeof(size_t)*3, &instanceSize, sizeof(size_t));

        for(size_t x = 0; x < size; x++)
        {

            memcpy(dataOut + sizeof(size_t)*4 + instanceSize*x, instance(x)->serialize(), instanceSize);

        }

    }

    return dataOut;

}

void Dataset::unserialize(char* dataIn)
{

    memcpy(&cardinality, dataIn, sizeof (size_t));
    memcpy(&dimensionality, dataIn + sizeof (size_t), sizeof (size_t));
    memcpy(&seed, dataIn + sizeof (size_t) + sizeof (size_t), sizeof (size_t));
    memcpy(&instanceSize, dataIn + sizeof(size_t)*3, sizeof(size_t));

    if(data != nullptr)
        destroyData();

    data = new Instance*[getCardinality()];
    for (size_t x = 0; x < getCardinality(); x++){
        data[x] = new Instance(x, getDimensionality());
    }

    char* aux = new char[instanceSize];
    for(size_t x = 0; x < getCardinality(); x++)
    {

        memcpy(aux, dataIn + sizeof(size_t)*4 + instanceSize*x, instanceSize);
        data[x]->unserialize(aux);

    }

    delete [] (aux);

}


void Dataset::saveToFile(std::string fileName)
{

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    char* ans = serialize();

    file.write(ans, serializedSize());
    file.close();


}


void Dataset::loadFromFile(std::string fileName)
{

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    char* dataIn = new char[4*sizeof (size_t)];
    file.read(dataIn, 4*sizeof (size_t));

    memcpy(&cardinality, dataIn, sizeof (size_t));
    memcpy(&dimensionality, dataIn + sizeof (size_t), sizeof (size_t));
    memcpy(&seed, dataIn + sizeof (size_t) + sizeof (size_t), sizeof (size_t));
    memcpy(&instanceSize, dataIn + sizeof(size_t)*3, sizeof(size_t));

    char* ans = new char[serializedSize()];
    file.seekg(0);
    file.read(ans, serializedSize());
    unserialize(ans);

    file.close();

    delete [] (dataIn);
    delete [] (ans);

}

