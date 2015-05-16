#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

template <typename T>
class Queue
{
protected:
    List<T> _queue;
    int lastIndex;

public:
    void qstore (const T &element);
    T qretrieve();
    T& getElement (int index);
    inline T& operator [] (int index){return getElement(index);}
    void printQueue(std::ostream& oStream, void(*printFunc)(std::ostream& os, const T& value));

    inline int len(){return _queue.Len();}

    Queue();
    ~Queue();
};



template<typename T>
Queue<T>::Queue()
{
  lastIndex=-1;
}

template<typename T>
Queue<T>::~Queue()
{
    _queue.clear();
}

template<typename T>
void Queue<T>::qstore(const T& element)
{
    _queue.add(element);
    lastIndex++;
}

template<typename T>
T Queue<T>::qretrieve()
{
    try
    {
        if (_queue.Len()==0) throw std::out_of_range("Queue is empty");

        T temp=_queue.at(0);
        _queue.removeAt(0);

        return temp;
    }
    catch(std::out_of_range){}
}

template <typename T>
T& Queue<T>::getElement (int index)
{
    try
    {
       if (index<0|| index>_queue.Len()-1) throw std::out_of_range("Incorrect index");

       return _queue[index];
    }
    catch(std::out_of_range){ }
}

template <typename T>
void Queue<T>::printQueue(std::ostream& oStream, void(*printFunc)(std::ostream& os, const T& value))
{
    _queue.printList(oStream, printFunc);
}

#endif // QUEUE_H
