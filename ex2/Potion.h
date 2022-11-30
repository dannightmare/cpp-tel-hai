#include "Item.h"
#include "Player.h"

class Potion : public Item
{
public:
    Potion(Player &owner) : owner(owner) {}
    char getLetter();

private:
    Player owner;
};