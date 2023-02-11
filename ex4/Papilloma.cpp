#include "Virus.h"

Papilloma::Papilloma(const std::string* name, int* genome, int viruslength)
  : Virus(name, genome, viruslength)
{
}

Papilloma::Papilloma(Virus& other)
  : Virus(other)
{
}

void
Papilloma::print(std::ostream& out) const
{
    out << 'P' << ' '; // was \t
    Virus::print(out);
}

Papilloma::~Papilloma() {}