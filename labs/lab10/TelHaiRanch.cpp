#include "Horse.h"
#include "Mule.h"

Animal::~Animal() {
    
}

Animal*
Donkey::reproduce(Animal& animal)
{
    if (animal.get_gender() == Animal::get_gender()) {
        return nullptr;
    }
    if (typeid(animal) == typeid(Donkey)) {
        return new Donkey(Animal::get_name() + " " + animal.get_name(),
                          *new Gender(std::rand() % 2));
    }
    if (typeid(animal) == typeid(Horse)) {
        return new Mule(Animal::get_name() + " " + animal.get_name(),
                        *new Gender(std::rand() % 2));
    }
    if (typeid(animal) == typeid(Mule)) {
        return nullptr;
    }
    std::cerr << "Donkey::reproduce got past all ifs" << std::endl;
    return nullptr;
}

Animal*
Horse::reproduce(Animal& animal)
{
    if (animal.get_gender() == Animal::get_gender()) {
        return nullptr;
    }
    if (typeid(animal) == typeid(Donkey)) {
        return new Mule(Animal::get_name() + " " + animal.get_name(),
                        *new Gender(std::rand() % 2));
    }
    if (typeid(animal) == typeid(Horse)) {
        return new Horse(Animal::get_name() + " " + animal.get_name(),
                         *new Gender(std::rand() % 2));
    }
    if (typeid(animal) == typeid(Mule)) {
        return nullptr;
    }
    std::cerr << "Horse::reproduce got past all ifs" << std::endl;
    return nullptr;
}

Animal*
Mule::reproduce(Animal& animal)
{
    return nullptr;
}

Animal*
Donkey::reproduce2(Animal& animal)
{
    if (animal.get_gender() == Animal::get_gender()) {
        return nullptr;
    }
    if (dynamic_cast<Donkey*>(&animal)) {
        return new Donkey(Animal::get_name() + " " + animal.get_name(),
                          *new Gender(std::rand() % 2));
    }
    if (dynamic_cast<Horse*>(&animal)) {
        return new Mule(Animal::get_name() + " " + animal.get_name(),
                        *new Gender(std::rand() % 2));
    }
    if (dynamic_cast<Mule*>(&animal)) {
        return nullptr;
    }
    std::cerr << "Donkey::reproduce got past all ifs" << std::endl;
    return nullptr;
}

Animal*
Horse::reproduce2(Animal& animal)
{
    if (animal.get_gender() == Animal::get_gender()) {
        return nullptr;
    }
    if (dynamic_cast<Donkey*>(&animal)) {
        return new Mule(Animal::get_name() + " " + animal.get_name(),
                        *new Gender(std::rand() % 2));
    }
    if (dynamic_cast<Horse*>(&animal)) {
        return new Horse(Animal::get_name() + " " + animal.get_name(),
                         *new Gender(std::rand() % 2));
    }
    if (dynamic_cast<Mule*>(&animal)) {
        return nullptr;
    }
    std::cerr << "Horse::reproduce got past all ifs" << std::endl;
    return nullptr;
}

Animal*
Mule::reproduce2(Animal& animal)
{
    return nullptr;
}