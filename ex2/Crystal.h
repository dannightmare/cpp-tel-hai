#ifndef CRYSTAL_H
#define CRYSTAL_H

#include "Item.h"
#include "Player.h"

class Crystal : public Item
{
  public:
    Crystal() = delete;
    virtual ~Crystal() override = default;
    Crystal(Player& owner)
      : owner(&owner)
    {
    }
    char getLetter() const override;
    const Player* getOwner() const override;

    // copy constructor
    Crystal(const Crystal& other)
      : Item()
      , owner(other.owner)
    {
    }

    // operator=
    Crystal& operator=(const Crystal& other);

  private:
    Player* owner;
};

#endif // CRYSTAL_H