#ifndef NODE_H
#define NODE_H


template<typename T>
class Node
{
public:
    T value;
    Node<T>* next, *prev;
    Node(const T &element);
    ~Node();

};

#endif // NODE_H

template<typename T>
Node<T>::Node(const T& element)
{
    next=nullptr;
    prev=nullptr;
    value=element;
}


template<typename T>
Node<T>::~Node()
{

}
