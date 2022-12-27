#include "Virus.h"

// Virus::Virus()
//   : size(0)
//   , genome(nullptr)
//   , name("")
// {
// }

Virus::Virus(const std::string& name, int* genome, int size)
  : size(size)
  , genome(std::move(genome))
{
    this->name = name;
}