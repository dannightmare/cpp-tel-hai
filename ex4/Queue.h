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
    T* array;
    int size;

    int head;
    int tail;

  public:
    Queue<T>(int size)
      : size(size)
    {
        array = new T[size];
    }
    Queue<T>(Queue<T>& other)
      : head(other.head)
      , tail(other.tail)
      , size(other.size)
    {
        array = new T[size];
        for (int i = head; i != tail; i = (i + 1) % size) {
            array[i] = other.array[i];
        }
    }
    ~Queue<T>() { delete[] array; }
    Queue<T>& operator=(Queue<T>& other)
    {
        delete[] array;

        head = other.head;
        tail = other.tail;
        size = other.size;

        array = new T[size];
        for (int i = head; i != tail; i = (i + 1) % size) {
            array[i] = other.array[i];
        }

        return *this;
    }
    void Enqueue(T& value)
    {
        tail = (tail + 1) % size;
        if (tail == head)
            throw std::exception();
        *array[tail] = value;
    }
    void EnqueueSorted(T& value)
    {
        int i = 0;
        for (int i = head; i != tail; i = (i + 1) % size) {
            if (value < array[i]) {
                break;
                ;
            }
        }
        tail = (tail + 1) % size;
        T tmp = value;
        for (int j = i; j != tail; j = (j + 1) % size) {
            swap(tmp, array[j]);
        }
    }
    T& Peek() { return array[head]; }
    T& Dequeue()
    {
        int tmp = head;
        head = (head + 1) % size;
        return array[tmp];
    }
};

#endif // QUEUE_H