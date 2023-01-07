#ifndef QUEUE_H
#define QUEUE_H

#include <exception>
template<class T>
void
swap(T* a, T* b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
class Node
{
    Node<T>* next;
    T& value;

  public:
    Node<T>()
      : next(nullptr)
      , value(0)
    {}
    Node<T>(T& value)
      : next(nullptr)
      , value(value)
    {}
    Node<T>(Node* other, T& value)
      : next(other)
      , value(value)
    {}
    ~Node<T>()
    {
        if (next != nullptr)
            delete next;
    }

    // getters/setters
    void setNext(Node* node) { next = node; }
    void setValue(T& value) { this->value = value; }
    Node* getNext() { return next; }
    T& getValue() { return value; }
};
/**
 * this class requires that the T class has the following:
 * operator=
 * operator<
 * copy c'tor
 */
template<class T>
class Queue
{
    Node<T>* head;
    Node<T>* tail;
    int size;

  public:
    Queue<T>()
      : head(nullptr)
      , tail(nullptr)
      , size(0)
    {}
    Queue<T>(Queue<T>& other)
      : head(other.head)
      , tail(other.tail)
      , size(other.size)
    {
        T tmp;
        int otherlen = other.size();
        for (int i = 0; i < otherlen; i++) {
            tmp = other.Dequeue();
            Enqueue(tmp);
            other.Enqueue(tmp);
        }
    }
    ~Queue<T>() { delete head; }
    Queue<T>& operator=(Queue<T>& other)
    {
        delete head;

        Node<T>tmp = other.head;
        while(tmp) {
            Enqueue(tmp.getValue());
            
            tmp = tmp.getNext();
        }

        return *this;
    }
    void Enqueue(T& value)
    {
        tail->setNext(new Node<T>(value));
    }
    void EnqueueSorted(T& value)
    {
        /// TODO: finish this
    }
    T& Peek() { return head->getValue(); }
    T& Dequeue()
    {
        int tmp = head->getValue();
        head = head->getNext();
        return tmp;
    }
};

#endif // QUEUE_H