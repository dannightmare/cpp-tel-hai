#include "Hole.h"
#include "Player.h"

char
Hole::getLetter() const
{
    return 'X';
}

const Player*
Hole::getOwner() const {
    return nullptr;
}