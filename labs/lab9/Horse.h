#ifndef HORSE_H
#define HORSE_H

#include "Animal.h"

class Horse : virtual public Animal
{
  public:
    virtual void speak() override
    {
        std::cout << Animal::get_name() << " Horse" << std::endl;
    }

    Horse() = delete;
    Horse(std::string name, Gender& gender)
      : Animal(name, gender)
    {}

    virtual Animal* reproduce(Animal& animal) override;

    virtual Animal* reproduce2(Animal& animal) override;
};

#endif // HORSE