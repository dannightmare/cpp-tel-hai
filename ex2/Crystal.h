#ifndef CRYSTAL_H

#include "Item.h"
#include "Player.h"

class Crystal : public Item
{
  public:
    Crystal(Player& owner)
      : owner(owner)
    {
    }
    char getLetter() const override;

  private:
    Player owner;
};

#endif // CRYSTAL_H