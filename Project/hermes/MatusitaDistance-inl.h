#ifndef MATUSITADISTANCEINL_H
#define MATUSITADISTANCEINL_H

/**
* Constructor.
*/
template <class ObjectType>
MatusitaDistance<ObjectType>::MatusitaDistance(){
}

/**
* Destructor.
*/
template <class ObjectType>
MatusitaDistance<ObjectType>::~MatusitaDistance(){
}

/**
* @deprecated Use getDistance(ObjectType &obj1, ObjectType &obj2) instead.
*
* @copydoc getDistance(ObjectType &obj1, ObjectType &obj2) .
*/
template <class ObjectType>
double MatusitaDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2){

    return getDistance(obj1, obj2);
}

/**
* Calculates the Euclidean distance between two feature vectors.
* This calculus is based on the math form sqrt((feature_1[i] - feature_2[i])^2).
* To make this computations both feature vectors should have the same size().
*
* @param obj1: The first feature vector.
* @param obj2: The second feature vector.
* @throw Exception If the computation is not possible.
* @return The Euclidean distance between feature vector 1 and feature vector 2.
*/
template <class ObjectType>
double MatusitaDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2){

//    if (obj1.size() != obj2.size()){
//        throw std::length_error("The feature vectors do not have the same size.");
//    }

    double d = 0;
    bool equal = true;

    for (size_t i = 0; i < obj1.size(); i++)
    {

        if(obj1[i] != obj2[i])
            equal = false;

        d = d + sqrt(obj1[i] * obj2[i]);

    }

    d = 1.0 - sqrt(1.0 - (d/obj1.size()));

    // Statistic support
    this->updateDistanceCount();

    if(equal)
        return 0.0;
    else return d;

}

#endif // MATUSITADISTANCEINL_H
