#ifndef COSINEDISTANCEINL_H
#define COSINEDISTANCEINL_H

#include <iostream>

template <class ObjectType>
CosineDistance<ObjectType>::CosineDistance(){
}

template <class ObjectType>
CosineDistance<ObjectType>::~CosineDistance(){
}

template <class ObjectType>
double CosineDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

template <class ObjectType>
double CosineDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double prod = 0.0, sqObj1 = 0.0, sqObj2 = 0.0;

    for(size_t i = 0; i < obj1.size(); i++)
    {

        prod = prod + obj1[i]*obj2[i];
        sqObj1 = sqObj1 + obj1[i]*obj1[i];
        sqObj2 = sqObj2 + obj2[i]*obj2[i];

    }

    sqObj1 = sqrt(sqObj1);
    sqObj2 = sqrt(sqObj2);

    // Statistic support
    this->updateDistanceCount();

    if(sqObj1 == sqObj2)
        return 0.0;
    else if((sqObj1 == 0.0) || (sqObj2 == 0.0))
        return 1.0;
    else
        return (1.0 - (prod/(sqObj1*sqObj2)));

}


#endif // COSINEDISTANCEINL_H
