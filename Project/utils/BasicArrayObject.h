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
#ifndef BASICARRAYOBJECT_H
#define BASICARRAYOBJECT_H

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>

/**
* This class implements a very important object for similarity search: just a single and simple
* feature vector that can make your life easier when talking about using arboretum resources. Be-
* cause of internal use on MAM's we must inherance from stObject class.
*
* For illustration, consider the feature vector as follows:
* +-----+------+------------------+
* | OID | Size | Vector Data []   |
* +-----+------+------------------+
*
* @brief This class implements a generic feature vector
* @author Marcos Vinicius Naves Bedo
* @version 1.0
* @arg DType The data type stored by each position of the feature vector
*/
template <class DType>
class BasicArrayObject{


    private:
        //The internal variable that really stores the data
        DType *data;
        //The size of the internal variable that really stores the data
        size_t dataSize;
        //The OID that identifies the feature vector
        u_int32_t OID;
        //A previous directive that can allow store and retrieve
        //the feature vector from BLOB or FILE
        char* serialized;

    public:

        /**
        * Constructor Method.
        * Sets data and size to empty and 0, respectively.
        */
        BasicArrayObject(){
            data = NULL;
            dataSize = 0;
            serialized = NULL;
        }

        /**
        * Constructor Method.
        * Initiates the dynamic vector behind the class.
        */
        BasicArrayObject(const u_int32_t OID, const size_t dataSize){

            this->OID = OID;
            data = new DType[dataSize];
            this->dataSize = dataSize;
            serialized = NULL;
        }

        /**
        * Constructor Method.
        * Sets the values of the vector to current.
        */
        BasicArrayObject(const u_int32_t OID, const DType &data, const size_t dataSize){

            this->OID = OID;
            this->data = data;
            this->dataSize = dataSize;
            serialized = NULL;
        }

        /**
        * Destructor.
        */
        ~BasicArrayObject(){

            if (data != NULL){
                delete[] data;
            }
            if (serialized != NULL){
                delete[] serialized;
            }
        }

        /**
        * @deprecated
        * @copydoc setOID(u_int32_t OID).
        */
        void SetOID(u_int32_t OID){

            setOID(OID);
        }


        /**
        * Sets the feature vector OID.
        * @param OID The OID of the feature vector.
        * Caution: The OID is not checked as unique.
        */
        void setOID(u_int32_t OID){
            this->OID = OID;
        }

        /**
        * Gets the feature vector OID.
        * @return The feature vector OID.
        */
        u_int32_t getOID() const{
            return OID;
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use getOID() instead.
        * @copydoc getOID().
        */
        u_int32_t GetOID() const{
            return getOID();
        }

        /**
        * @copydoc set(DType value).
        */
        void Set(DType value){
            set(value);
        }

        /**
        * Sets a specific value in a specific position.
        * @todo Throw a out-of-bounds exception.
        * @param pos The position of the insertion.
        * @param value The value to be pushed.
        */
        void set(size_t pos, DType value){

            data[pos] = value;
        }

        /**
        * Gets the entire stored data.
        * @return The entire stored data.
        */
        DType *getData(){

            return data;
        }

        /**
        * Overloaded operator allowing modifications.
        * @param idx The index to be queried.
        */
        DType& operator[] (size_t idx) {

            return data[idx];
        }

        /**
        * Overloaded operator that not allows modifications.
        * @param idx The index to be queried.
        */
        const DType& operator[] (size_t idx)  const{

            return data[idx];
        }

        /**
        * Get a value in a specific position.
        * @todo Throw a out-of-bounds exception.
        * @param idx The position value to be retrieved.
        * @return The value of the position idx.
        */
        DType get(size_t idx){

            return data[idx];
        }

        /**
        * @brief This method is deprecated, but still necessary for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use get(u_int32_t idx) instead.
        * @copydoc get(size_t idx).
        */
        DType Get(size_t idx){

            return get(idx);
        }

        /**
        * Gets the number of elements in the feature vector.
        * @return The number of elements of the feature vector.
        */
        size_t getSize(){

            return dataSize;
        }

        size_t size(){

            return getSize();
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use getSize() instead.
        * @copydoc getSize().
        */
        size_t GetSize(){

            return getSize();
        }

        /**
        * @deprecated
        * @copydoc getObject().
        */
        BasicArrayObject<DType> GetObject(){

            return getObject();
        }

        /**
        * Return the instance of the current Basic Array Object.
        * @return The current instance of Basic Array Object.
        */
        BasicArrayObject<DType> getObject(){

            return this;
        }

        /**
        * Gets an instantied copy of the object.
        * @return A copy of the object.
        */
        BasicArrayObject<DType> *clone(){

            return new BasicArrayObject<DType>(getOID(), getData(), getSize());
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use clone() instead.
        * @copydoc clone().
        */
        BasicArrayObject<DType> *Clone(){

            return clone();
        }

        /**
        * Check if the obj is equal to the current object.
        * @param obj The object to be compared.
        * @return True if the objects are equal, else otherwise.
        */
        bool isEqual(BasicArrayObject<DType> *obj){

            if ((getOID() != obj->GetOID()) || (getSize() != obj->GetSize()))
                return false;

            for (size_t x = 0; x < dataSize; x++)
                if ((this->get(x)) != ((DType) (obj->Get(x)))) //Change Dtype*
                    return false;

            return true;
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use isEqual(stObject *obj) instead.
        * @copydoc isEqual(stObject *obj).
        */
        bool IsEqual(BasicArrayObject<DType> *obj){

            return isEqual(obj);
        }

        /**
        * Gets the size of the byte vector.
        * @return The size of the bytes vector.
        */
        u_int32_t getSerializedSize(){

            return (sizeof(u_int32_t) + sizeof(size_t) +  (sizeof(DType) * dataSize));
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use getSerializedSize() instead.
        * @copydoc getSerializedSize().
        */
        u_int32_t GetSerializedSize(){

            return getSerializedSize();
        }

        /**
        * Gets the equivalent byte vector of the object.
        * @return The equivalent byte vector of the object.
        */
        char* serialize(){

            if (serialized == NULL){
                serialized = new char[getSerializedSize()];
                size_t size = getSize();
                memcpy(serialized, &OID, sizeof(u_int32_t));
                memcpy(serialized + sizeof(u_int32_t), &size, sizeof(size_t));
                for (size_t x = 0; x < size; x++){
                    memcpy(serialized + sizeof(u_int32_t) + sizeof(size_t)+(sizeof(DType)*x), &data[x], sizeof(DType));
                }
            }
            return serialized;
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated. Use serialize() instead.
        * @copydoc serialize().
        */
        const u_int8_t *Serialize(){

            return serialize();
        }

        /**
        * Gets the equivalent byte vector of the object.
        * @return The equivalent string byte vector of the object.
        */
        std::string serializeToString(){

            std::string answer;

            serialize();
            for (int x = 0; x < getSerializedSize(); x++){
                answer += serialized[x];
            }

            return answer;
        }

        /**
        * Transform a byte vector into an object.
        * @param dataIn The byte vector.
        * @param dataSize The byte vector size.
        */
        void unserialize(char* dataIn, size_t dataSize = 0){

//            DType *d = 0;
            size_t size_vector;

            // This is the reverse of Serialize(). So the steps are similar.
            // Remember, the format of the serizalized object is
            // +----------+-----------+--------+
            // | OID | Size | Vector Data []   |
            // +----------+-----------+--------+

            memcpy(&OID, dataIn, sizeof(u_int32_t));

            if (dataSize != 0) {
                size_vector = (dataSize - sizeof(u_int32_t) - sizeof(size_t)) / sizeof(DType);
            } else {
                memcpy(&size_vector, dataIn + sizeof(u_int32_t), sizeof(size_t));
            }

            if (data != NULL){
                delete[] data;
                data = new DType[size_vector];
            }

            for (size_t x = 0; x < size_vector; x++){
                memcpy(&data[x], dataIn + sizeof(u_int32_t) + sizeof(size_t) + (sizeof(DType)*x), sizeof(DType));
            }


            // Since we have changed the object contents, we must invalidate the old
            // serialized version if it exists. In fact we, may copy the given serialized
            // version of tbe new object to the buffer but we don't want to spend memory.
            if (serialized != NULL){
                delete [] serialized;
                serialized = NULL;
            }//end if
        }

        /**
        * @brief This method is deprecated, but still usefull for arboretum
        * template functions.
        * @deprecated This method is deprecated.
        * Use unserialize(const u_int8_t *dataIn, u_int32_t dataSize) instead.
        * @copydoc unserialize(const u_int8_t *dataIn, size_t dataSize).
        */
        void Unserialize(const u_int8_t *dataIn, size_t dataSize = 0){

            unserialize(dataIn, dataSize);
        }

        /**
        * @copydoc unserialize(const u_int8_t *dataIn, size_t dataSize).
        */
        void unserializeFromString(std::string dataIn){

            size_t size_vector;
            DType *d;

            // This is the reverse of Serialize(). So the steps are similar.
            // Remember, the format of the serizalized object is
            // +----------+-----------+--------+
            // | OID | Size | Vector Data []   |
            // +----------+-----------+--------+

            memcpy(&OID, dataIn.c_str(), sizeof(u_int32_t));
            memcpy(&size_vector, dataIn.c_str() + sizeof(u_int32_t), sizeof(size_t));

            if (data != NULL){
                delete[] data;
                data = new DType[size_vector];
            }

            for (size_t x = 0; x < size_vector; x++){
                memcpy(&data[x], dataIn.c_str() + sizeof(u_int32_t) + sizeof(size_t) + (sizeof(DType)*x), sizeof(DType));
            }


            // Since we have changed the object contents, we must invalidate the old
            // serialized version if it exists. In fact we, may copy the given serialized
            // version of tbe new object to the buffer but we don't want to waste memory.
            if (serialized != NULL){
                delete [] serialized;
                serialized = NULL;
            }//end if
        }

        std::string toString()
        {
            std::string str = "[";
            for(size_t i = 0; i < size(); i++){
                str += std::to_string(get(i));
                if(i != (size()-1)) str += ", ";
                else str += "]";
            }
            return str;
        }

        std::string toString(std::string separator)
        {

            std::string str = "";
            for(size_t i = 0; i < size(); i++){
                str += std::to_string(get(i));
                if(i != (size()-1)) str += separator;
            }
            return str;

        }

        std::string toStringWithOID()
        {
            std::string str = std::to_string(this->OID) + " -> " + "[";
            for(size_t i = 0; i < size(); i++){
                str += std::to_string(get(i));
                if(i != (size()-1)) str += ", ";
                else str += "]";
            }
            return str;
        }

//        const u_int8_t *serialize(){

//            if (serialized == NULL){
//                serialized = new u_int8_t[getSerializedSize()];
//                size_t size = getSize();
//                memcpy(serialized, &OID, sizeof(u_int32_t));
//                memcpy(serialized + sizeof(u_int32_t), &size, sizeof(size_t));
//                for (size_t x = 0; x < size; x++){
//                    memcpy(serialized + sizeof(u_int32_t) + sizeof(size_t)+(sizeof(DType)*x), &data[x], sizeof(DType));
//                }
//            }
//            return serialized;
//        }

//        void unserialize(const u_int8_t *dataIn, size_t dataSize = 0){

////            DType *d = 0;
//            size_t size_vector;

//            // This is the reverse of Serialize(). So the steps are similar.
//            // Remember, the format of the serizalized object is
//            // +----------+-----------+--------+
//            // | OID | Size | Vector Data []   |
//            // +----------+-----------+--------+

//            memcpy(&OID, dataIn, sizeof(u_int32_t));

//            if (dataSize != 0) {
//                size_vector = (dataSize - sizeof(u_int32_t) - sizeof(size_t)) / sizeof(DType);
//            } else {
//                memcpy(&size_vector, dataIn + sizeof(u_int32_t), sizeof(size_t));
//            }

//            if (data != NULL){
//                delete[] data;
//                data = new DType[size_vector];
//            }

//            for (size_t x = 0; x < size_vector; x++){
//                memcpy(&data[x], dataIn + sizeof(u_int32_t) + sizeof(size_t) + (sizeof(DType)*x), sizeof(DType));
//            }


//            // Since we have changed the object contents, we must invalidate the old
//            // serialized version if it exists. In fact we, may copy the given serialized
//            // version of tbe new object to the buffer but we don't want to spend memory.
//            if (serialized != NULL){
//                delete [] serialized;
//                serialized = NULL;
//            }//end if
//        }


};

typedef BasicArrayObject<double> Instance;

#endif
