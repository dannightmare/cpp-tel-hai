#include "Virus.h"
#include <iostream>

#ifndef CULTURE_H
#define CULTURE_H

class Culture
{
    Virus target;
    Virus** viruses = nullptr;
    int virusesamount;
    int viruslength;
    int mutations;

    void sort();

  public:
    Culture(const std::string* names,
            int** matrix,
            int virusesamount,
            int viruslength,
            Virus target,
            int mutations);
    ~Culture();

    Virus& getVirus(int i);
    Virus& operator[](int i);

    void operator++(int);
};

#endif // CULTURE_H