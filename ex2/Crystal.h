#include "Item.h"
#include "Player.h"

class Crystal : public Item
{
public:
    char getLetter() override;

private:
    Player owner;
};