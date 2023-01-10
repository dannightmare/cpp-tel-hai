#ifndef DONKEY_H
#define DONKEY_H

#include "Animal.h"
#include "Horse.h"

class Donkey : virtual public Animal
{
  public:
    virtual void speak() override
    {
        std::cout << Animal::get_name() << " Donkey" << std::endl;
    }

    Donkey() = delete;
    Donkey(std::string name, Gender& gender)
      : Animal(name, gender)
    {}

    virtual Animal* reproduce(Animal& animal) override;

    virtual Animal* reproduce2(Animal& animal) override;
};

#endif // DONKEY_H