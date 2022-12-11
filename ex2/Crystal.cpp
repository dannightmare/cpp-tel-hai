#include "Crystal.h"

char
Crystal::getLetter() const
{
    return owner->getLower();
}

const Player*
Crystal::getOwner() const
{
    return owner;
}

Crystal&
Crystal::operator=(const Crystal& other)
{

    if (this != &other) {
        owner = other.owner;
    }
    return *this;
}