#ifndef KULCZYNSKIDISTANCE_H
#define KULCZYNSKIDISTANCE_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class KulczynskiDistance : public DistanceFunction<ObjectType>{

    public:

        KulczynskiDistance();
        virtual ~KulczynskiDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "KulczynskiDistance-inl.h"
#endif // KULCZYNSKIDISTANCE_H
