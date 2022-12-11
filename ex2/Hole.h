#ifndef HOLE_H
#define HOLE_H

#include "Item.h"

class Hole : public Item
{
public:
    char getLetter() const override;
};

#endif // HOLE_H