#ifndef DIRECTORYNODE_H
#define DIRECTORYNODE_H

#include <Node.h>
#include <cstring>
#include <iostream>
#include <sstream>



template<class Dtype>
class DirectoryNode : public Node<Dtype>
{

    //Private
    private:
        size_t s_bounds_size;

        //Getters
        size_t getBoundsSize();

        //Setters
        void setSerializeVariables(size_t _bounds_size);


    //Public
    public:
        DirectoryNode();
        DirectoryNode(Node<Dtype>* _parent, std::vector<DynamicArray<Dtype>> _bounds);
        ~DirectoryNode();

        //Virtual
        bool isDirectoryNode();
        bool isLeafNode();
        bool equals(Node<Dtype>* other);
        std::string toString();
        u_int32_t getSerializeSize();
        u_char* serialize();
        void unserialize(u_char* data);


};



template<class Dtype>
size_t DirectoryNode<Dtype>::getBoundsSize()
{

    return s_bounds_size;

}



template<class Dtype>
void DirectoryNode<Dtype>::setSerializeVariables(size_t _s_bounds_size)
{

    s_bounds_size = _s_bounds_size;

}



template<class Dtype>
DirectoryNode<Dtype>::DirectoryNode()
{

    this->setLeftNode(nullptr);
    this->setRightNode(nullptr);
    this->setParentNode(nullptr);
    this->setBoundary(std::vector<DynamicArray<Dtype>>());
    this->setNodeID(0);

}



template<class Dtype>
DirectoryNode<Dtype>::DirectoryNode(Node<Dtype>* _parent, std::vector<DynamicArray<Dtype>> _bounds)
{

    this->setLeftNode(nullptr);
    this->setRightNode(nullptr);
    this->setParentNode(_parent);
    this->setBoundary(_bounds);
    this->setNodeID(0);

}



template<class Dtype>
DirectoryNode<Dtype>::~DirectoryNode()
{

    if(this->getBoundary().size() > 0)
    {

        this->getBoundary().clear();

    }

}



template<class Dtype>
bool DirectoryNode<Dtype>::isDirectoryNode()
{

    return true;

}



template<class Dtype>
bool DirectoryNode<Dtype>::isLeafNode()
{

    return false;

}



template<class Dtype>
bool DirectoryNode<Dtype>::equals(Node<Dtype>* other)
{

    bool ans = true;

    if(other->isLeafNode())
    {

        ans = false;

    }
    else
    {

        ans = this->equalBounds(other->getBoundary());

    }

    return ans;

}



template<class Dtype>
std::string DirectoryNode<Dtype>::toString()
{

    std::stringstream st;
    st << "Node ID = " << this->getNodeID() << "\n";
    st << "Bounds : " << this->showBounds() << "\n";
    return st.str();

}



template<class Dtype>
u_int32_t DirectoryNode<Dtype>::getSerializeSize()
{

    setSerializeVariables(this->getBoundary().size());
    return sizeof(u_int32_t) * 2 + getBoundsSize() * (sizeof(Dtype) * 2);

}



template<class Dtype>
u_char* DirectoryNode<Dtype>::serialize()
{

    u_char* data = nullptr;

    if(data == nullptr)
    {

        data = new u_char[getSerializeSize()];
        u_int32_t nodeID = (u_int32_t)this->getNodeID(), boundsSize = (u_int32_t)s_bounds_size, total = 0;

        memcpy(data + total, &nodeID, sizeof(u_int32_t));
        total += sizeof(u_int32_t);
        memcpy(data + total, &boundsSize, sizeof(u_int32_t));
        total += sizeof(u_int32_t);

        for(size_t x = 0; x < boundsSize; x++)
        {

            Dtype arr[2];
            arr[0] = this->getBoundary()[x].array[0];
            arr[1] = this->getBoundary()[x].array[1];

            memcpy(data + total, &arr[0], sizeof(Dtype));
            total += sizeof(Dtype);
            memcpy(data + total, &arr[1], sizeof(Dtype));
            total += sizeof(Dtype);

        }

    }

    return data;

}



template<class Dtype>
void DirectoryNode<Dtype>::unserialize(u_char* data)
{

    u_int32_t nodeID = 0, boundsSize = 0, total = 0;

    memcpy(&nodeID, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);
    memcpy(&boundsSize, data + total, sizeof(u_int32_t));
    total += sizeof(u_int32_t);

    this->setNodeID((size_t)nodeID);
    s_bounds_size = (size_t)boundsSize;
    setSerializeVariables(getBoundsSize());

    std::vector<DynamicArray<Dtype>> vecBounds;

    for(size_t x = 0; x < getBoundsSize(); x++)
    {

        Dtype arr[2];
        memcpy(&arr[0], data + total, sizeof(Dtype));
        total += sizeof(Dtype);
        memcpy(&arr[1], data + total, sizeof(Dtype));
        total += sizeof(Dtype);

        vecBounds.push_back(DynamicArray<Dtype>(arr));

    }

    this->setBoundary(vecBounds);

}



#endif // DIRECTORYNODE_H
