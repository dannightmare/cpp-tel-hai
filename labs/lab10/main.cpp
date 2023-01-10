// #include <iostream>
#include "LinkedList.h"

int
main(void)
{
    LinkedList<int> ll;
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        ll.Insert(&arr[i]);
    }
    std::cout << ll << std::endl;
    *ll[2] = 1337;
    std::cout << ll << std::endl;
    return 0;
}