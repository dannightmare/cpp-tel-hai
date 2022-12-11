

#include "Player.h"
#include <cctype>

char
Player::getCapital() const
{
    return toupper(letter);
}

char
Player::getLower() const
{
    return tolower(letter);
}