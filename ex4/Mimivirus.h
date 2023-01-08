#ifndef MIMIVIRUS_H
#define MIMIVIRUS_H

#include "Virus.h"

class Mimivirus : public Virus
{
  public:
    Mimivirus() = delete;
    Mimivirus(std::string name, int* genome, int viruslength);
};

#endif // MIMIVIRUS_H