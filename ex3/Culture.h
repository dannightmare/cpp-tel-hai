#include "Virus.h"

#ifndef CULTURE_H
#define CULTURE_H

class Culture
{
    Virus target;
    Virus** culture = nullptr;
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

    void operator++(int);



};

#endif // CULTURE_H