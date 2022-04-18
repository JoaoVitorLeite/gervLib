#ifndef KULCZYNSKIDISTANCEINL_H
#define KULCZYNSKIDISTANCEINL_H

template <class ObjectType>
KulczynskiDistance<ObjectType>::KulczynskiDistance(){
}

template <class ObjectType>
KulczynskiDistance<ObjectType>::~KulczynskiDistance(){
}

template <class ObjectType>
double KulczynskiDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

template <class ObjectType>
double KulczynskiDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double d = 0;

    for (size_t i = 0; i < obj1.size(); i++)
    {

        d = d + fabs(obj1[i] - obj2[i])/fmin(obj1[i], obj2[i]);

    }

    // Statistic support
    this->updateDistanceCount();


    return d/obj1.size();
}

#endif // KULCZYNSKIDISTANCEINL_H
