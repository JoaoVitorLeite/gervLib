#ifndef TANIMOTODISTANCE_H
#define TANIMOTODISTANCE_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class TanimotoDistance : public DistanceFunction<ObjectType>{

    public:

        TanimotoDistance();
        virtual ~TanimotoDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "TanimotoDistance-inl.h"
#endif // TANIMOTODISTANCE_H
