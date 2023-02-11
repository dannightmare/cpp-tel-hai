#include "Virus.h"

Mimivirus::Mimivirus(const std::string* name, int* genome, int viruslength)
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
    out << 'M' << ' ';  // was \t
    Virus::print(out);
}

Mimivirus::~Mimivirus() {}