

#include <cctype>
#include "Player.h"

char Player::getCapital()
{
    return toupper(letter);
}

char Player::getLower() 
{
    return tolower(letter);
}