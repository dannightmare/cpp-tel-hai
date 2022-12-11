#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Player.h"

class Potion : public Item
{
public:
    Potion() : Item() {}
    Potion(Player &owner) : Item(), owner(owner) {}
    char getLetter() const override;
    const Player *getOwner() const;

private:
    Player owner;
};

#endif // POTION_H