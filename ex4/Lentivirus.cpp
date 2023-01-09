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
}