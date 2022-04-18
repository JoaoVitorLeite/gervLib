#ifndef PARSERARGUMENTS_H
#define PARSERARGUMENTS_H

#include <Dataset.h>
#include <Pivots.h>
#include <Hermes.h>
#include <vector>

class ParserArguments
{
public:
    ParserArguments();
    ~ParserArguments();

    std::vector<std::string> split(std::string str, std::string delimiter="[//s+,;]");

    // NOME-PORCENTAGEM-OUTRO
    Pivot* parsePivot(std::string pivot, std::string separator, Dataset* data, DistanceFunction<Instance>* df, size_t nPivots, size_t seed);

    Pivot* parsePivot(std::string pivot, double sampleSize, Dataset* data, DistanceFunction<Instance>* df, size_t nPivots, size_t seed);

    DistanceFunction<Instance>* parseDistanceFunction(std::string df);

    std::string getPivotName(PIVOT_TYPE pivotType);


};

#endif // PARSERARGUMENTS_H
