#include "Transformer.h"

Transformer::Transformer()
  : Robot(1, 25)
  , is_flying(false)
{}

Transformer::~Transformer() {}
Transformer&
Transformer::operator=(const Transformer& other)
{
    if (this != &other) {
        Robot::operator=(other);
    }
    return *this;
}
Transformer::Transformer(const Transformer& other)
  : Robot(other)
  , is_flying(other.is_flying)
{}

void
Transformer::move(std::string& str)
{
    char tmp = str[getLocation()];
    str[getLocation()] = getLetter();
    std::cout << str << std::endl;
    str[getLocation()] = tmp;

    if (is_flying) {
        setLocation(getLocation() + getSpeed());
    } else if (str[getLocation() + 1] == '_') {
        setLocation(getLocation() + getSpeed());
    }
    if (getLocation() >= str.length())
        return;
    if (std::rand() % 100 < getChance()) {
        transform();
    }
}

void
Transformer::transform()
{
    is_flying = !is_flying;
    if (is_flying) {
        setSpeed(2);
    } else {
        setSpeed(1);
    }
}