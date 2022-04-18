#ifndef COSINEDISTANCE_H
#define COSINEDISTANCE_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class CosineDistance : public DistanceFunction<ObjectType>{

    public:

        CosineDistance();
        virtual ~CosineDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "CosineDistance-inl.h"
#endif // COSINEDISTANCE_H
