#pragma once
#include "Queue.h"
#include "Virus.h"
#include <iostream>


class Culture
{
    int viruslength;
    int virusesamount;
    static Virus* target;      // single virus object
    Queue<Virus> queue;        // queue
                               // int mutations;
    std::string const** m_names; // array
    int* variants;             // array
  public:
    void sort();

    Culture(int virusesamount, int viruslength);
    // Culture(const std::string* names,
    //         int** matrix,
    //         int virusesamount,
    //         int viruslength,
    //         Virus* target,
    //         int mutations);
    ~Culture();

    void add(Virus* virus);
    void remove(Virus* virus);

    static void setTarget(Virus* vector);

    Virus* getVirus(int i);
    Virus& getBestVirus();
    Virus* operator[](int i);

    void operator++(int);

    static double calculate_factor(const Virus& virus1, const Virus& virus2);

    Virus& variant(Virus& virus);

    friend bool operator<(const Virus& virus1, const Virus& virus2);
    friend std::ostream& operator<<(std::ostream& out, const Culture& culture);
};