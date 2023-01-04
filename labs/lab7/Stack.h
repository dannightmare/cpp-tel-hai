#include <iostream>
#include "List.h"

class Stack
{
public:
    // the five big ones
    Stack() : l(new List()) {}
    Stack(Stack &o);
    Stack(Stack &&o);
    void operator=(Stack &o);
    void operator=(Stack &&o);
    ~Stack();

    // stack implementation
    void push(int a);
    int pop();
    int tail();
    bool empty();
    void transfer(Stack &other);

    // operators
    int operator*();
    void operator~();
    bool operator!();
    void operator<<(int a);
    void operator>>(int &a);
    void operator<<(Stack &o);
    void operator>>(Stack &o);
    friend std::ostream &operator<<(std::ostream &co, Stack &s);

private:
    List *l;
};