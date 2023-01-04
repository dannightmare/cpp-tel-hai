#include "Robot.h"

Robot::Robot()
  : speed(1)
  , chance(30)
{}

Robot::~Robot() {}

Robot&
Robot::operator=(const Robot& other)
{
    if (this != &other) {
        speed = other.speed;
        chance = other.chance;
    }
    return *this;
}

Robot::Robot(const Robot& other)
  : speed(other.speed)
  , chance(other.chance)
{}

Robot::Robot(int speed, int chance)
  : speed(speed)
  , chance(chance)
{}

void
Robot::move(std::string& str)
{
    char tmp = str[getLocation()];
    str[getLocation()] = getLetter();
    std::cout << str << std::endl;
    str[getLocation()] = tmp;

    if (str[getLocation() + 1] == '_') {
        setLocation(getLocation() + getSpeed());
    }
    if (getLocation() >= str.length())
        return;
    if (std::rand() % 100 < getChance()) {
        str[getLocation() + 1] = '_';
    }
}
