#ifndef LORENTZIAN_H
#define LORENTZIAN_H

#include "DistanceFunction.h"
#include <cmath>
#include <stdexcept>

template <class ObjectType>
class LorentzianDistance : public DistanceFunction<ObjectType>{

    public:

        LorentzianDistance();
        virtual ~LorentzianDistance();

        double GetDistance(ObjectType &obj1, ObjectType &obj2);
        double getDistance(ObjectType &obj1, ObjectType &obj2);
};

#include "Lorentzian-inl.h"
#endif // LORENTZIAN_H
