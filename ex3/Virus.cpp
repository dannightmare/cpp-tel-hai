#include "Virus.h"

Virus::Virus()
  : size(0)
  , vector(nullptr)
  , name("")
{}

Virus::Virus(const std::string& name, const std::string& vector)
  : name(name)
{
    this->name = name;
    std::stringstream ss;
    ss << vector;
    int i = 0;
    std::string temp;
    while (ss >> temp)
        i++;
    size = i;
    this->vector = new int[size];
    
}