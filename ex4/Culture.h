#include "Queue.h"
#include "Virus.h"
#include <iostream>

#ifndef CULTURE_H
#define CULTURE_H

class Culture
{
    int viruslength;
    Virus* target;             // single virus object
    Virus** viruses = nullptr; // matrix of viruses
    int virusesamount;
    int mutations;
    std::string* names; // array
    int* variants;      // array

    void sort();

  public:
    Culture(const std::string* names,
            int** matrix,
            int virusesamount,
            int viruslength,
            Virus* target,
            int mutations);
    ~Culture();

    Virus& getVirus(int i);
    Virus& operator[](int i);

    void operator++(int);

    double calculate_factor(Virus& virus1, Virus& virus2);

    Virus& variant(Virus& virus);
};

#endif // CULTURE_H