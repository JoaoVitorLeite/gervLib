#ifndef SOERGEL_H
#define SOERGEL_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class SoergelDistance : public DistanceFunction<ObjectType>{

    public:

        SoergelDistance();
        virtual ~SoergelDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "Soergel-inl.h"
#endif // SOERGEL_H
