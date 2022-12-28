#include "Virus.h"
#include <string>

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

double
Virus::calculate_factor(const Virus& other)
{
    double countmisfits = 0;
    for (int i = 0; i < size; i++) {
        std::cout << "debug: Virus::calculate_factor(): iteration " << i
                  << std::endl;
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
    // std::cout << name << " got to start of variant()" << std::endl;

    if (underscore == -1) {
        name = name + "_1";
    } else {
        int variant = std::stoi(name.substr(underscore + 1));
        name = name.substr(0, underscore) + "_" + std::to_string(variant + 1);
    }
    // std::cout << name << " got to mid of variant()" << std::endl;

    Virus* virus = new Virus(*this);
    // std::cout << name << " got to postmid of variant()" << std::endl;

    virus->name = name;
    /// debug
    // std::cout << name << " got to end of variant()" << std::endl;
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
    std::cout << virus.getName() << " ";
    for (int i = 0; i < virus.size; i++) {
        std::cout << virus.genome[i] << " ";
    }
    std::cout << std::endl;
    return out;
}