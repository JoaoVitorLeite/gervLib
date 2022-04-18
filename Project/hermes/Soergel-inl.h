#ifndef SOERGELINL_H
#define SOERGELINL_H

template <class ObjectType>
SoergelDistance<ObjectType>::SoergelDistance(){
}

template <class ObjectType>
SoergelDistance<ObjectType>::~SoergelDistance(){
}

template <class ObjectType>
double SoergelDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

template <class ObjectType>
double SoergelDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double d = 0;

    for (size_t i = 0; i < obj1.size(); i++)
    {

        d = d + fabs(obj1[i] - obj2[i])/fmax(obj1[i], obj2[i]);

    }

    // Statistic support
    this->updateDistanceCount();


    return d/obj1.size();
}


#endif // SOERGELINL_H
