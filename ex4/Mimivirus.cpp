#include "Mimivirus.h"

Mimivirus::Mimivirus(std::string name, int* genome, int viruslength)
  : Virus(name, genome, viruslength)
{
}

Mimivirus::Mimivirus(Virus& other)
  : Virus(other)
{
}

void
Mimivirus::print(std::ostream& out) const
{
    out << 'M' << '\t';
    Virus::print(out);
    // if (getVariant() != 0) {
    //     out << "_" << getVariant();
    // }
    // out << "\t";

    // for (int i = 0; i < getSize(); i++) {
    //     out << Virus::operator[](i) << " ";
    // }
}