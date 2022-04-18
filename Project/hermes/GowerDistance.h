#ifndef GOWERDISTANCE_H
#define GOWERDISTANCE_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class GowerDistance : public DistanceFunction<ObjectType>{

    public:

        GowerDistance();
        virtual ~GowerDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "GowerDistance-inl.h"
#endif // GOWERDISTANCE_H
