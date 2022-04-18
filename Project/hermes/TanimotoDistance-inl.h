#ifndef TANIMOTODISTANCEINL_H
#define TANIMOTODISTANCEINL_H

template <class ObjectType>
TanimotoDistance<ObjectType>::TanimotoDistance(){
}

template <class ObjectType>
TanimotoDistance<ObjectType>::~TanimotoDistance(){
}

template <class ObjectType>
double TanimotoDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

template <class ObjectType>
double TanimotoDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double denominator = 0, numerator = 0;

    for (size_t i = 0; i < obj1.size(); i++)
    {

        denominator = denominator + fmax(obj1[i], obj2[i]);
        numerator = numerator + (fmax(obj1[i], obj2[i]) - fmin(obj1[i], obj2[i]));

    }

    // Statistic support
    this->updateDistanceCount();

    if(denominator == 0.0) return 0.0;
    else return (numerator/denominator);

}


#endif // TANIMOTODISTANCEINL_H
