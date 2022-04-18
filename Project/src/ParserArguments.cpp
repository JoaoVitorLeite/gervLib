#include "ParserArguments.h"


ParserArguments::ParserArguments()
{


}


ParserArguments::~ParserArguments()
{


}


std::vector<std::string> ParserArguments::split(std::string str, std::string delimiter)
{

    std::regex rgx(delimiter);
    std::sregex_token_iterator iter(str.begin(),str.end(),rgx,-1);
    std::sregex_token_iterator end;
    std::vector<std::string> v;

    for(; iter != end; ++iter)
    {

        v.push_back(*iter);

    }

    return v;

}


// NOME-PORCENTAGEM-OUTRO
Pivot* ParserArguments::parsePivot(std::string pivot, std::string separator, Dataset* data, DistanceFunction<Instance>* df, size_t nPivots, size_t seed)
{

    Pivot* pvt = nullptr;
    std::vector<std::string> v = split(pivot, separator);

    Dataset* sample = new Dataset(data->sample(size_t(data->getCardinality()*std::stod(v[1])), false, seed), size_t(data->getCardinality()*std::stod(v[1])), data->getDimensionality());

    if(v[0] == "RANDOM")
        pvt = new RandomPivots(sample, nPivots, seed);
    else if(v[0] == "GNAT")
        pvt = new GnatPivots(sample, df, nPivots, seed);
    else if(v[0] == "CONVEX")
        pvt = new ConvexPivots(sample, df, nPivots, seed);
    else if(v[0] == "KMEDOIDS")
    {

        if(v.size() == 2)
            pvt = new KmedoidsPivots(sample, df, nPivots, seed);
        else
            pvt = new KmedoidsPivots(sample, df, nPivots, seed, size_t(std::stoi(v[2])));

    }
    else if(v[0] == "MAXSEPARETED")
        pvt = new MaxSeparetedPivots(sample, df, nPivots, seed);
    else if(v[0] == "MAXVARIANCE")
        pvt = new MaxVariancePivots(sample, df, nPivots, seed);
    else if(v[0] == "SELECTION")
    {

        if(v.size() == 2)
            pvt = new SelectionPivots(sample, df, nPivots, sample->getCardinality()/2, seed);
        else
            pvt = new SelectionPivots(sample, df, nPivots, size_t(std::stod(v[2])), seed);

    }
    else if(v[0] == "PCA")
        pvt = new PCAPivots(sample, df, nPivots, seed);
    else if(v[0] == "SSS")
    {

        if(v.size() == 2)
            pvt = new SSSPivots(sample, df, nPivots, seed);
        else
            pvt = new SSSPivots(sample, df, nPivots, seed, std::stod(v[2]));

    }
    else
        throw std::invalid_argument("Pivot selection not find !_!");

    return pvt;

}


Pivot* parsePivot(std::string pivot, double sampleSize, Dataset* data, DistanceFunction<Instance>* df, size_t nPivots, size_t seed)
{

    Pivot* pvt = nullptr;
    Dataset* sample = new Dataset(data->sample(size_t(data->getCardinality()*sampleSize), false, seed), size_t(data->getCardinality()*sampleSize), data->getDimensionality());

    if(pivot == "RANDOM")
        pvt = new RandomPivots(sample, nPivots, seed);
    else if(pivot == "GNAT")
        pvt = new GnatPivots(sample, df, nPivots, seed);
    else if(pivot == "CONVEX")
        pvt = new ConvexPivots(sample, df, nPivots, seed);
    else if(pivot == "KMEDOIDS")
        pvt = new KmedoidsPivots(sample, df, nPivots, seed);
    else if(pivot == "MAXSEPARETED")
        pvt = new MaxSeparetedPivots(sample, df, nPivots, seed);
    else if(pivot == "MAXVARIANCE")
        pvt = new MaxVariancePivots(sample, df, nPivots, seed);
    else if(pivot == "SELECTION")
        pvt = new SelectionPivots(sample, df, nPivots, seed);
    else if(pivot == "PCA")
        pvt = new PCAPivots(sample, df, nPivots, seed);
    else if(pivot == "SSS")
        pvt = new SSSPivots(sample, df, nPivots, seed);
    else
        throw std::invalid_argument("Pivot selection not find !_!");

    return pvt;

}


DistanceFunction<Instance>* ParserArguments::parseDistanceFunction(std::string df)
{

    DistanceFunction<Instance>* ans = nullptr;

    if(df == "EUCLIDEAN")
        ans = new EuclideanDistance<Instance>();
    else if(df == "COSINE")
        ans = new CosineDistance<Instance>();
    else if(df == "BRAYCURTIS")
        ans = new BrayCurtisDistance<Instance>();
    else if(df == "TANIMOTO")
        ans = new TanimotoDistance<Instance>();
    else if(df == "MATUSITA")
        ans = new MatusitaDistance<Instance>();
    else
    {

        throw std::invalid_argument("Not find distance function !_!");

    }

    return ans;

}


std::string ParserArguments::getPivotName(PIVOT_TYPE pivotType)
{

    std::string names[] = {"RANDOM", "GNAT", "CONVEX", "KMEDOIDS", "MAXSEPARETED", "MAXVARIANCE", "SELECTION", "PCA", "SSS"};

    return names[pivotType];

}

