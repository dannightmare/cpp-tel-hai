#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(Stack &o)
{
    l = new List();
    for (int i = o.l->size() - 1; i >= 0; i--)
    {
        l->insert(o.l->operator[](i));
    }
}

Stack::Stack(Stack &&o)
{
    l = o.l;
    o.l = nullptr;
}

void Stack::operator=(Stack &o)
{
    if (&o == this)
        return;

    l->clear();
    for (int i = o.l->size() - 1; i >= 0; i--)
    {
        l->insert(o.l->operator[](i));
    }
}

void Stack::operator=(Stack &&o)
{
    if (&o == this)
        return;

    l = o.l;
    o.l = nullptr;
}

Stack::~Stack()
{
    delete l;
}

void Stack::push(int a)
{
    l->insert(a);
}

int Stack::pop()
{
    if (empty())
    {
        cerr << "Stack is empty" << endl;
        exit(2);
    }
    int x = (*l)[0];
    l->remove(x);
    return x;
}

bool Stack::empty()
{
    return l->size() == 0;
}

void Stack::transfer(Stack &o)
{
    while (!empty())
        o.push(pop());
}

int Stack::operator*()
{
    return (*l)[0];
}

void Stack::operator~()
{
    l->clear();
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
    int head = 0;
    while (head < s.l->size())
        co << s.l->operator[](head++) << " ";

    return co;
}