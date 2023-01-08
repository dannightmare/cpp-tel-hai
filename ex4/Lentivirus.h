#ifndef LENTIVIRUS_H
#define LENTIVIRUS_H

#include "Virus.h"

class Lentivirus : public Virus
{
  public:
    Lentivirus() = delete;
    Lentivirus(std::string name, int* genome, int viruslength);
};

#endif // LENTIVIRUS_H