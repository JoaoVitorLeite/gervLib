#ifndef LORENTZIANINL_H
#define LORENTZIANINL_H

template <class ObjectType>
LorentzianDistance<ObjectType>::LorentzianDistance(){
}

template <class ObjectType>
LorentzianDistance<ObjectType>::~LorentzianDistance(){
}

template <class ObjectType>
double LorentzianDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

template <class ObjectType>
double LorentzianDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double d = 0;

    for (size_t i = 0; i < obj1.size(); i++)
    {

        d = d + log(1 + fabs(obj1[i] - obj2[i]));

    }

    // Statistic support
    this->updateDistanceCount();


    return d;
}


#endif // LORENTZIANINL_H
