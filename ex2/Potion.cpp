#include "Potion.h"
#include "Player.h"

char
Potion::getLetter() const
{
    return owner.getCapital();
}

const Player*
Potion::getOwner() const
{
    return &owner;
}