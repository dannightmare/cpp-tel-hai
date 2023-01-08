#include "Mimivirus.h"

Mimivirus::Mimivirus(std::string name, int* genome, int viruslength)
  : Virus(name, genome, viruslength)
{
}

void
Mimivirus::print(std::ostream& out) const
{
    out << 'M' << '\t' << getName();
    if (getVariant() != 0) {
        out << "_" << getVariant();
    }
    out << "\t";

    for (int i = 0; i < getSize(); i++) {
        out << Virus::operator[](i) << " ";
    }
}