#include "ConvexPivots.h"


ConvexPivots::ConvexPivots()
{

    setPivotType(PIVOT_TYPE::CONVEX);

}


ConvexPivots::~ConvexPivots()
{

}


void ConvexPivots::generatePivots(Dataset *sample, DistanceFunction<Instance> *df, size_t nPivots)
{
    setNumberOfPivots(nPivots);

    size_t drop = 2;
    size_t currentPivot = 0, p1, pos = 0;
    size_t *aux;
    double max = std::numeric_limits<double>::min();

    bool *bitmap = new bool[sample->getCardinality()];
    size_t *pvtIndex = new size_t[getNumberOfPivots()+drop];

    aux = uniqueRandomNumber(0, sample->getCardinality(), 1, getSeed());
    p1 = aux[0];

    //Inicializa bitmap
    for (size_t x = 0; x < sample->getCardinality(); x++)
        bitmap[x] = false;

    //Incializa ponteiros de pivôs
    for (size_t x = 0; x < getNumberOfPivots()+drop; x++)
        pvtIndex[x] = 0;

    //Cria primeiro pivô aleatório
    bitmap[p1] = true;

    //Calcula a distância do primeiro pivô aleatório para toda a amostra
    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        double dist = df->getDistance(*sample->instance(x), *sample->instance(p1));

        if(dist > max)
        {

            max = dist;
            pos = x;

        }

    }

    //Insere elemento mais afastado na lista de pivôs
    bitmap[pos] = true;
    pvtIndex[currentPivot] = pos;
    currentPivot++;

    max = std::numeric_limits<double>::min();
    pos = 0;

    //Calcula a distância do elemento mais afastado do elemento mais distante do primeiro pivô aleatório para toda a amostra
    for(size_t x = 0; x < sample->getCardinality(); x++)
    {

        double dist = df->getDistance(*sample->instance(x), *sample->instance(pvtIndex[0]));

        if((dist > max) && (!bitmap[x]))
        {

            max = dist;
            pos = x;

        }

    }

    //Insere elemento mais afastado mais distante do primeiro pivô na lista de pivôs
    bitmap[pos] = true;
    pvtIndex[currentPivot] = pos;
    currentPivot++;

    //Definição da primeira aresta
    double edge = df->getDistance(*sample->instance(pvtIndex[0]), *sample->instance(pvtIndex[1]));

    while ((currentPivot-drop) < getNumberOfPivots())
    {

        double error = 0;
        double min = std::numeric_limits<double>::max();
        pos = 0;

        for(size_t x = 0; x < sample->getCardinality(); x++)
        {

            if(!bitmap[x])
            {

                error = 0;
                for(size_t y = 0; y < currentPivot; y++)
                    error += std::abs(edge - df->getDistance(*sample->instance(pvtIndex[y]), *sample->instance(x)));


                if(min > error)
                {

                    min = error;
                    pos = x;

                }

            }

        }

        bitmap[pos] = true;
        pvtIndex[currentPivot] = pos;
        currentPivot++;

    }

    //Transfere os pivôs que foram marcados no bitmap para a lista de pivôs herdada de Pivot
    for(size_t x = drop; x < (getNumberOfPivots()+drop); x++)
        setPivot(sample->instance(pvtIndex[x]), x-drop);


    delete[] bitmap;
    delete[] pvtIndex;
    delete[] aux;

}
