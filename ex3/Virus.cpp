#include "Virus.h"
#include <string>

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
    genome = new int[size];
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
    name = other.name;
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
    int x = rand() % size;
    int y = rand() % size;

    if (x == y)
        return;
    
    int tmp = genome[x];
    genome[x] = genome[y];
    genome[y] = tmp;
}

double
Virus::calculate_factor(const Virus& other)
{
    double countmisfits = 0;
    for (int i = 0; i < size; i++) {
        if (genome[i] == other.genome[i])
            countmisfits++;
    }

    return 1 - (countmisfits / size);
}

Virus&
Virus::variant()
{
    std::string name = this->name;
    int underscore = name.find("_");

    if (underscore == -1) {
        name = name + "_1";
    } else {
        int variant = std::stoi(name.substr(underscore + 1));
        name = name.substr(0, underscore) + "_" + std::to_string(variant + 1);
    }

    Virus* virus = new Virus(*this);

    virus->name = name;
    return *virus;
}

std::string
Virus::getName() const
{
    return name;
}

std::ostream&
operator<<(std::ostream& out, const Virus& virus)
{
    std::cout << virus.getName();
    for (int i = 0; i < virus.size; i++) {
        std::cout << " " << virus.genome[i];
    }
    return out;
}