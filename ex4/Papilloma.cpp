#include "Papilloma.h"

Papilloma::Papilloma(std::string name, int* genome, int viruslength)
  : Virus(name, genome, viruslength)
{
}

void
Papilloma::print(std::ostream& out) const
{
    out << 'P' << '\t' << getName();
    if (getVariant() != 0) {
        out << "_" << getVariant();
    }
    out << "\t";

    for (int i = 0; i < getSize(); i++) {
        out << Virus::operator[](i) << " ";
    }
}