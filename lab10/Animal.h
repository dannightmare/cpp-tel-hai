#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Gender
{
    bool gender; // male = true, female = false

  public:
    Gender(bool gender)
      : gender(gender){};
    bool operator==(const Gender& other) const
    {
        return gender == other.gender;
    }
};

class Animal
{
    std::string name;
    Gender gender;

  public:
    virtual void speak() = 0;

    // abstract class
    Animal() = delete;
    Animal(std::string name, Gender& gender)
      : name(name)
      , gender(gender){};
    virtual ~Animal() = 0;
    Gender& get_gender() { return gender; }
    std::string& get_name() { return name; }

    virtual Animal* reproduce(Animal&) = 0;
    virtual Animal* reproduce2(Animal&) = 0;
};

#endif // ANIMAL_H