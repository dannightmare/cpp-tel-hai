#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack s;
    s.push(50);
    s.push(10);
    s.push(23);

    cout << *s << endl;
    ~s;
    cout << !s << endl;
    s << 5;
    int a = 0;
    s >> a;
    cout << a << endl;

    s << a;
    s << 7;
    s << 6;

    Stack s2;
    s2 << s;
    cout << *s2 << endl;

    s2 >> s;
    cout << *s << endl;
    cout << s << endl;

    Stack s3(s);
    cout << s3 << endl;
    s2 = move(s);
    cout << s2 << endl;
    return 0;
}