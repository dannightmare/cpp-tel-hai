#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(Stack &o)
{
    maxSize = o.maxSize;
    head = o.head;
    delete[] data;
    data = new int[maxSize];
    for (int i = 0; i <= head; i++)
    {
        data[i] = o.data[i];
    }
}

Stack::Stack(Stack &&o)
{
    data = o.data;
    head = o.head;
    maxSize = o.maxSize;

    o.data = nullptr;
}

void Stack::operator=(Stack &o)
{
    if (&o == this)
        return;

    maxSize = o.maxSize;
    head = o.head;
    delete[] data;
    data = new int[maxSize];
    for (int i = 0; i <= head; i++)
    {
        data[i] = o.data[i];
    }
}

void Stack::operator=(Stack &&o)
{
    if (&o == this)
        return;
    delete[] data;
    data = o.data;
    head = o.head;
    maxSize = o.maxSize;

    o.data = nullptr;
}

Stack::~Stack()
{
    delete[] data;
}

void Stack::push(int a)
{
    if (head == maxSize - 1)
    {
        cerr << "Stack is full" << endl;
        exit(1);
    }
    data[++head] = a;
}

int Stack::pop()
{
    if (empty())
    {
        cerr << "Stack is empty" << endl;
        exit(2);
    }
    return data[head--];
}

bool Stack::empty()
{
    return head == -1;
}

void Stack::transfer(Stack &o)
{
    while (!empty())
        o.push(pop());
}

int Stack::operator*()
{
    return data[head];
}

void Stack::operator~()
{
    head = -1;
}

bool Stack::operator!()
{
    return empty();
}

void Stack::operator<<(int a)
{
    push(a);
}

void Stack::operator>>(int &a)
{
    a = pop();
}

void Stack::operator<<(Stack &o)
{
    o.transfer(*this);
}

void Stack::operator>>(Stack &o)
{
    transfer(o);
}

ostream &operator<<(ostream &co, Stack &s)
{
    int head = s.head;
    while (head >= 0)
        co << s.data[head--] << " ";

    return co;
}

// class Node
// {
// public:
//     Node(int a) : val(a)
//     {
//     }
//     void setVal(int a)
//     {
//         val = a;
//     }
//     int getVal()
//     {
//         return val;
//     }
//     void setNext(Node &o)
//     {
//         next = &o;
//     }
//     Node *getNext()
//     {
//         return next;
//     }

// private:
//     int val;
//     Node *next;
// };