#include "Virus.h"

// Virus::Virus()
//   : size(0)
//   , genome(nullptr)
//   , name("")
// {
// }

Virus::Virus(const std::string& name, int* genome, int size)
  : size(size)
  , name(name)
{
    this->genome = new int[size];
    for (int i = 0; i < size; i++) {
        this->genome[i] = genome[i];
    }
}

Virus::~Virus()
{
    delete[] genome;
}

Virus::Virus(Virus& other)
{
    size = other.size;
    for (int i = 0; i < size; i++) {
        genome[i] = other.genome[i];
    }
    name = other.name;
}
Virus&
Virus::operator=(Virus& other)
{
    // size stays unchanged
    for (int i = 0; i < size; i++) {
        genome[i] = other.genome[i];
    }
    return *this;
}
Virus::Virus(Virus&& other)
{
    genome = other.genome;
    other.genome = nullptr;
    size = other.size;
    name = other.name;
}
Virus&
Virus::operator=(Virus&& other)
{
    delete[] genome;
    genome = other.genome;
    other.genome = nullptr;
    name = other.name;
    return *this;
}

void
Virus::operator*()
{
    int x = rand() % size + 1;
    int y = rand() % size + 1;

    int tmp = genome[x];
    genome[x] = genome[y];
    genome[y] = tmp;
}