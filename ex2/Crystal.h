#include "Item.h"
#include "Player.h"

class Crystal : public Item
{
public:
    Crystal(Player &owner) : owner(owner) {}
    char getLetter() override;

private:
    Player owner;
};