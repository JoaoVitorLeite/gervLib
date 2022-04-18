#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <sstream>



template <class Dtype>
struct DynamicArray
{

    Dtype array[2];

    DynamicArray(Dtype _array[2])
    {

        array[0] = _array[0];
        array[1] = _array[1];

    }

    DynamicArray()
    {



    }

};



template<class Dtype>
class Node
{

    //Private
    private:
        Node<Dtype> *left, *right, *parent;
        std::vector<DynamicArray<Dtype>> bounds;
        size_t nodeID;

    //Public
    public:

    //Constructors and destructors
        Node();
        Node(Node* _left, Node* _right);
        Node(Node* _left, Node* _right, Node* _parent);
        Node(Node* _left, Node* _right, Node* _parent, std::vector<DynamicArray<Dtype>> _bounds);
        virtual ~Node();

    //Public methods
        bool isRoot();
        bool equalBounds(std::vector<DynamicArray<Dtype>> other);
        std::string showBounds();

    //Getters
        std::vector<DynamicArray<Dtype>> getBoundary();
        Node* getLeft();
        Node* getRight();
        Node* getParent();
        size_t getNodeID();

    //Setters
        void setLeftNode(Node* _left);
        void setRightNode(Node* _right);
        void setParentNode(Node* _parent);
        void setBoundary(std::vector<DynamicArray<Dtype>> _bounds);
        void setNodeID(size_t _nodeID);
        void setBounds(DynamicArray<Dtype> dim, size_t pos);

    //Virtual
        virtual bool isDirectoryNode() = 0;
        virtual bool isLeafNode() = 0;
        virtual bool equals(Node<Dtype>* other) = 0;
        virtual std::string toString() = 0;
        virtual u_int32_t getSerializeSize() = 0;
        virtual u_char* serialize() = 0;
        virtual void unserialize(u_char* data) = 0;

};

template<class Dtype>
Node<Dtype>::Node()
{

    setLeftNode(nullptr);
    setRightNode(nullptr);
    setParentNode(nullptr);
    setBoundary(std::vector<DynamicArray<Dtype>>());
    setNodeID(0);

}



template<class Dtype>
Node<Dtype>::Node(Node* _left, Node* _right)
{

    setLeftNode(_left);
    setRightNode(_right);
    setParentNode(nullptr);
    setBoundary(std::vector<DynamicArray<Dtype>>());
    setNodeID(0);

}



template<class Dtype>
Node<Dtype>::Node(Node* _left, Node* _right, Node* _parent)
{

    setLeftNode(_left);
    setRightNode(_right);
    setParentNode(_parent);
    setBoundary(std::vector<DynamicArray<Dtype>>());
    setNodeID(0);

}



template<class Dtype>
Node<Dtype>::Node(Node* _left, Node* _right, Node* _parent, std::vector<DynamicArray<Dtype>> _bounds)
{

    setLeftNode(_left);
    setRightNode(_right);
    setParentNode(_parent);
    setBoundary(_bounds);
    setNodeID(0);

}



template<class Dtype>
Node<Dtype>::~Node<Dtype>()
{



}



template<class Dtype>
bool Node<Dtype>::isRoot()
{

    return getParent() == nullptr;

}



template<class Dtype>
bool Node<Dtype>::equalBounds(std::vector<DynamicArray<Dtype>> other)
{

    if(other.size() != bounds.size())
        return false;
    else
    {

        for(size_t x = 0; x < bounds.size(); x++)
        {

            if((bounds[x].array[0] != other[x].array[0]) || (bounds[x].array[1] != other[x].array[1]))
                return false;

        }

    }

    return true;

}



template<class Dtype>
std::string Node<Dtype>::showBounds()
{

    std::stringstream result;

    result << "[";

    for(size_t x = 0; x < bounds.size(); x++)
    {

        result << "<" << std::to_string(bounds[x].array[0]) << ", " << std::to_string(bounds[x].array[1]) << ">";

        if(x != (bounds.size() - 1))
            result << ", ";

    }

    result << "]";

    return result.str();

}


template<class Dtype>
std::vector<DynamicArray<Dtype>> Node<Dtype>::getBoundary()
{

    return bounds;

}



template<class Dtype>
Node<Dtype>* Node<Dtype>::getLeft()
{

    return left;

}



template<class Dtype>
Node<Dtype>* Node<Dtype>::getRight()
{

    return right;

}



template<class Dtype>
Node<Dtype>* Node<Dtype>::getParent()
{

    return parent;

}



template<class Dtype>
size_t Node<Dtype>::getNodeID()
{

    return nodeID;

}



template<class Dtype>
void Node<Dtype>::setLeftNode(Node* _left)
{

    left = _left;

}



template<class Dtype>
void Node<Dtype>::setRightNode(Node* _right)
{

    right = _right;

}



template<class Dtype>
void Node<Dtype>::setParentNode(Node* _parent)
{

    parent = _parent;

}



template<class Dtype>
void Node<Dtype>::setBoundary(std::vector<DynamicArray<Dtype>> _bounds)
{

    bounds = _bounds;

}



template<class Dtype>
void Node<Dtype>::setNodeID(size_t _nodeID)
{

    nodeID = _nodeID;

}

template<class Dtype>
void Node<Dtype>::setBounds(DynamicArray<Dtype> dim, size_t pos)
{

    if((pos < 0) || (pos > getBoundary().size()))
    {

        throw std::out_of_range("Out of range");

    }
    else
    {

        bounds[pos] = dim;

    }

}



#endif // NODE_H
