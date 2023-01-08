#ifndef PAPILLOMA_H
#define PAPILLOMA_H

#include "Virus.h"

class Papilloma : public Virus
{

  public:
    Papilloma() = delete;
    Papilloma(std::string name, int* genome, int viruslength);
};

#endif // PAPILLOMA_H