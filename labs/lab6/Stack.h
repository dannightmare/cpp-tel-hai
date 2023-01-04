#include <iostream>

class Stack
{
public:
    // the five big ones
    Stack() = delete;
    Stack(int maxSize) : maxSize(maxSize), head(-1), data(new int[maxSize]) {}
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
    int *data;
    int head;
    int maxSize;
};