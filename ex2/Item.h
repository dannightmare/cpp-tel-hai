#ifndef ITEM_H
#define ITEM_H
#include "Player.h"

/**
 * This behaves like the interface for all items
 * on the matrix.
 */
class Item
{
  public:
    virtual ~Item() = 0;
    virtual char getLetter() const = 0;
    const virtual Player* getOwner() const = 0;
};

#endif // ITEM_H