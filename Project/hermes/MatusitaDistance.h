#ifndef MATUSITADISTANCE_H
#define MATUSITADISTANCE_H

#include "DistanceFunction.h"
#include <cmath>
//#include <stdexcept>

/**
* Class to obtain the Euclidean (or geometric) Distance
*
* @brief L2 distance class.
* @author 006.
* @version 1.0.
*/
template <class ObjectType>
class MatusitaDistance : public DistanceFunction <ObjectType>{

    public:

        MatusitaDistance();
        virtual ~MatusitaDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "MatusitaDistance-inl.h"
#endif // MATUSITADISTANCE_H
