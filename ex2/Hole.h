#ifndef HOLE_H
#define HOLE_H

#include "Item.h"

class Hole : public Item
{
  public:
    Hole() = default;
    ~Hole() = default;
    char getLetter() const override;
    const Player * getOwner() const override;

    // copy constructor no fields
    Hole(const Hole & rhs) = delete;

    // operator= same as constructor
    Hole & operator=(const Hole & rhs) = delete;

    // move constructor and operator= unnecessary

};

#endif // HOLE_H