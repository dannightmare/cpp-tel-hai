#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Player.h"

class Potion : public Item
{
  public:
    Potion() = delete;
    ~Potion() = default;
    Potion(Player& owner)
      : Item()
      , owner(&owner)
    {
    }
    char getLetter() const override;
    const Player* getOwner() const override;

    // copy constructor
    Potion(const Potion& other)
      : Item()
      , owner(other.owner)
    {
    }
    // operator=
    Potion& operator=(const Potion& other);

  private:
    Player* owner;
};

#endif // POTION_H