#ifndef PAPILLOMA_H
#define PAPILLOMA_H

#include "Virus.h"

class Papilloma : public Virus
{

  public:
    Papilloma() = delete;
    Papilloma(std::string name, int* genome, int viruslength);

    virtual void operator*() override { Virus::operator*(); }
};

#endif // PAPILLOMA_H