#include "Lentivirus.h"
#include "Virus.h"

Lentivirus::Lentivirus(std::string name, int* genome, int viruslength)
  : Virus(name, genome, viruslength)
{
}

Lentivirus::Lentivirus(Virus& other)
  : Virus(other)
{
}

void
Lentivirus::print(std::ostream& out) const
{
    out << 'L' << '\t';
    Virus::print(out);
    // if (getVariant() != 0) {
    //     out << "_" << getVariant();
    // }
    // out << "\t";

    // for (int i = 0; i < getSize(); i++) {
    //     out << Virus::operator[](i) << " ";
    // }
}