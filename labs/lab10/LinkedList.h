#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
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
    T* value;

  public:
    Node<T>()
      : next(nullptr)
      , value(0)
    {}
    Node<T>(T* value)
      : next(nullptr)
      , value(value)
    {}
    Node<T>(Node* other, T* value)
      : next(other)
      , value(value)
    {}

    // getters/setters
    void setNext(Node* node) { next = node; }
    void setValue(T* value) { this->value = value; }
    Node* getNext() { return next; }
    T* getValue() { return value; }
};
/**
 * this class requires that the T class has the following:
 * operator=
 * operator<
 * copy c'tor
 */
template<class T>
class LinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size;

  public:
    LinkedList<T>()
      : head(nullptr)
      , tail(nullptr)
      , size(0)
    {}

    ~LinkedList<T>() { delete head; }

    void Insert(T* value)
    {
        Node<T>* tmp = new Node<T>(value);
        // if head is null then tail is null
        // since list is empty
        if (head != nullptr && tail != nullptr) {
            tail->setNext(tmp);
        } else {
            head = tmp;
        }
        tail = tmp;
        ++size;
    }

    void Insert(T* value, int index)
    {
        Node<T>* tmp_ins = new Node<T>(value);
        Node<T>* tmp_index = head;
        for (int i = 0; i < index; ++i) {
            tmp_index = tmp_index->getNext();
        }
        tmp_ins->setNext(tmp_index->getNext());
        tmp_index->setNext(tmp_ins);
    }

    T* Peek() { return head->getValue(); }

    bool Remove(T* value)
    {
        if (head->getValue() == value) {
            head = head->getNext();
            return true;
        }
        Node<T>* node = head;

        while (node->getNext() != tail) {
            if (node->getNext()->getValue() == value) {
                Node<T>* tmp_node = node->getNext();
                node->setNext(tmp_node->getNext());
                delete tmp_node;
                return true;
            }
            node = node->getNext();
        }

        if (tail->getValue() == value) {
            delete tail;
            tail = node;
            return true;
        }
        return false;
    }

    // tested and working
    void clear()
    {
        while (head != nullptr) {
            Node<T>* tmp = head->getNext();
            delete head;
            head = tmp;
        }
        tail = nullptr;
        size = 0;
    }
    int getSize() { return size; }

    T* operator[](int index) {
        Node<T>* node = head;
        for(int i = 0; i < index; ++i) {
            if(node == nullptr) return nullptr;
            node = node->getNext();
        }
        return node->getValue();
    }

    // tested and working
    friend std::ostream& operator<<(std::ostream& out,
                                    const LinkedList<T>& queue)
    {
        Node<T>* tmp = queue.head;
        while (tmp) {
            out << *tmp->getValue() << std::endl;
            tmp = tmp->getNext();
        }

        return out;
    }
};

#endif // QUEUE_H