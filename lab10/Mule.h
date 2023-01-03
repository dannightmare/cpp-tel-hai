#ifndef MULE_H
#define MULE_H

#include "Animal.h"
#include "Donkey.h"
#include "Horse.h"

class Mule
  : public Horse
  , public Donkey
{
  public:
    virtual void speak() override
    {
        std::cout << Animal::get_name() << " Mule" << std::endl;
    }

    Mule() = delete;
    Mule(std::string name, Gender& gender)
      : Animal(name, gender)
      , Horse(name, gender)
      , Donkey(name, gender)
    {}

    virtual Animal* reproduce(Animal& animal) override;

    virtual Animal* reproduce2(Animal& animal) override;
};

#endif // MULE_H