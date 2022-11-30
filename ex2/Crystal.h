#include "Item.h"
#include "Player.h"

class Crystal : Item
{
public:
    char getLetter();

private:
    Player owner;
};