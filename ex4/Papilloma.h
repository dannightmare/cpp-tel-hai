#ifndef PAPILLOMA_H
#define PAPILLOMA_H

#include "Virus.h"

class Papilloma : public Virus
{

  public:
    Papilloma() = delete;
    Papilloma(std::string name, int* genome, int viruslength);
    Papilloma(Virus& other);
    ~Papilloma() override;

    virtual void print(std::ostream& out) const override;

    virtual void operator*() override { Virus::operator*(); }
};

#endif // PAPILLOMA_H