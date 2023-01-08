#include "Queue.h"
#include "Virus.h"
#include <iostream>

#ifndef CULTURE_H
#define CULTURE_H

class Culture
{
    int viruslength;
    int virusesamount;
    static Virus* target; // single virus object
    Queue<Virus> queue;   // queue
    // int mutations;
    std::string* names; // array
    int* variants;      // array

    void sort();

  public:
    Culture(int virusesamount, int viruslength);
    // Culture(const std::string* names,
    //         int** matrix,
    //         int virusesamount,
    //         int viruslength,
    //         Virus* target,
    //         int mutations);
    ~Culture();

    void add(Virus* vector);

    static void setTarget(Virus* vector);

    Virus& getVirus(int i);
    Virus& getBestVirus();
    Virus& operator[](int i);

    void operator++(int);

    static double calculate_factor(const Virus& virus1, const Virus& virus2);

    Virus& variant(Virus& virus);

    friend bool operator<(const Virus& virus1, const Virus& virus2);
    friend std::ostream& operator<<(std::ostream& out, const Culture& culture);
};

#endif // CULTURE_H