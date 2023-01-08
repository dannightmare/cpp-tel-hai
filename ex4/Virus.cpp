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
    variant = other.variant;
}

Virus&
Virus::operator=(Virus& other)
{
    if (this == &other) {
        return *this;
    }
    // size stays unchanged
    for (int i = 0; i < size; i++) {
        genome[i] = other.genome[i];
    }
    name = other.name;
    variant = other.variant;
    return *this;
}
Virus::Virus(Virus&& other)
{
    genome = other.genome;
    other.genome = nullptr;
    size = other.size;
    name = other.name;
    variant = other.variant;
}

Virus&
Virus::operator=(Virus&& other)
{
    if (this == &other) {
        return *this;
    }
    delete[] genome;
    genome = other.genome;
    other.genome = nullptr;
    name = other.name;
    variant = other.variant;
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

int
Virus::getNum(int n) const
{
    if (n < 0 || n > size) {
        std::cerr << "Virus::getNum(int n): " << n << " out of bounds"
                  << std::endl;
        exit(20);
    }
    return genome[n];
}

void
Virus::print(std::ostream& out) const
{
    out << getName();
    if (variant != 0) {
        out << "_" << variant;
    }
    out << "\t";

    for (int i = 0; i < size; i++) {
        out << genome[i] << " ";
    }
}

std::ostream&
operator<<(std::ostream& out, const Virus& virus)
{
    virus.print(out);

    return out;
}

void
Virus::setVariant(int variant)
{
    if (variant <= 0) {
        std::cerr << "Virus::setVariant: variant invalid " << variant
                  << std::endl;
        exit(25);
    }
    this->variant = variant;
}
