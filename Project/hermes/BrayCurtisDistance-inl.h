/* Copyright 2003-2017 GBDI-ICMC-USP <caetano@icmc.usp.br>
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*   http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* Constructor.
*/
template <class ObjectType>
BrayCurtisDistance<ObjectType>::BrayCurtisDistance(){
}

/**
* Destructor.
*/
template <class ObjectType>
BrayCurtisDistance<ObjectType>::~BrayCurtisDistance(){}

/**
* @copydoc DistanceFunction::GetDistance()
*/
template <class ObjectType>
double BrayCurtisDistance<ObjectType>::GetDistance(ObjectType &obj1, ObjectType &obj2)/* throw (std::length_error)*/{

    return getDistance(obj1, obj2);
}

/**
* @copydoc DistanceFunction::getDistance()
*/
template <class ObjectType>
double BrayCurtisDistance<ObjectType>::getDistance(ObjectType &obj1, ObjectType &obj2)/* throw (std::length_error)*/{

    if (obj1.size() != obj2.size()){
        throw std::length_error("The feature vectors do not have the same size.");
    }

    double d;
    double tmpNumerator;
    double tmpDenominator;

    d = 0;
    for (size_t i = 0; i < obj1.size(); i++){
        tmpNumerator   = fabs(obj1[i] -  obj2[i]);
        tmpDenominator = obj1[i]  +  obj2[i];

        if (!(tmpDenominator == 0.0)){
            d = d + (tmpNumerator/tmpDenominator);
        }
    }

    // Statistic support
    this->updateDistanceCount();

    return d;
}
