#include "Virus.h"
#include <string>

Virus::Virus(const std::string* name, int* genome, int size)
  : m_size(size)
  , m_name(name)
{
    m_genome = new int[size];
    for (int i = 0; i < size; i++) {
        m_genome[i] = genome[i];
    }
}

Virus::~Virus()
{
    delete[] m_genome;
}

Virus::Virus(Virus& other)
{
    m_size = other.m_size;
    m_genome = new int[m_size];
    for (int i = 0; i < m_size; i++) {
        m_genome[i] = other.m_genome[i];
    }
    m_name = other.m_name;
    m_variant = other.m_variant;
}

Virus&
Virus::operator=(Virus& other)
{
    if (this == &other) {
        return *this;
    }
    // size stays unchanged
    for (int i = 0; i < m_size; i++) {
        m_genome[i] = other.m_genome[i];
    }
    m_name = other.m_name;
    m_variant = other.m_variant;
    return *this;
}
Virus::Virus(Virus&& other)
{
    m_genome = other.m_genome;
    other.m_genome = nullptr;
    m_size = other.m_size;
    m_name = other.m_name;
    m_variant = other.m_variant;
}

Virus&
Virus::operator=(Virus&& other)
{
    if (this == &other) {
        return *this;
    }
    delete[] m_genome;
    m_genome = other.m_genome;
    other.m_genome = nullptr;
    m_name = other.m_name;
    m_variant = other.m_variant;
    return *this;
}

void
Virus::operator*()
{
    int x = rand() % m_size;
    int y = rand() % m_size;

    if (x == y)
        return;

    int tmp = m_genome[x];
    m_genome[x] = m_genome[y];
    m_genome[y] = tmp;
}

int
Virus::getNum(int n) const
{
    if (n < 0 || n > m_size) {
        std::cerr << "Virus::getNum(int n): " << n << " out of bounds"
                  << std::endl;
        exit(20);
    }
    return m_genome[n];
}

void
Virus::print(std::ostream& out) const
{
    out << getName();
    if (m_variant != 0) {
        out << "_" << m_variant;
    }
    out << " "; // was \t

    for (int i = 0; i < m_size; i++) {
        out << m_genome[i] << " ";
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
    this->m_variant = variant;
}
