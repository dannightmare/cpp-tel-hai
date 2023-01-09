#include "Papilloma.h"

Papilloma::Papilloma(std::string name, int* genome, int viruslength)
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
    out << 'P' << '\t';
    Virus::print(out);
}

Papilloma::~Papilloma() {}