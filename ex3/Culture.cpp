#include "Culture.h"

Culture::Culture(const std::string* names,
                 int** matrix,
                 int virusesamount,
                 int viruslength,
                 Virus target,
                 int mutations)
  : virusesamount(virusesamount)
  , viruslength(viruslength)
  , target(target)
  , mutations(mutations)
{
    culture = new Virus*[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        culture[i] = new Virus(names[i], matrix[i], viruslength);
    }
    sort();
}

Culture::~Culture()
{
    for (int i = 0; i < virusesamount; i++) {
        delete[] culture[i];
    }
    delete[] culture;
    delete &target;
}

void
Culture::operator++(int)
{
    for (int i = 0; i < virusesamount; i++) {
        for (int j = 0; j < mutations; j++)
            *(*culture[i]);
    }

    sort();
    *culture[virusesamount - 1] = *culture[0];
}

void
Culture::sort()
{
}