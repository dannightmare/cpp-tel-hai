#ifndef MIMIVIRUS_H
#define MIMIVIRUS_H

#include "Virus.h"

class Mimivirus : public Virus
{
  public:
    Mimivirus() = delete;
    Mimivirus(std::string name, int* genome, int viruslength);
    Mimivirus(Virus& other);
    ~Mimivirus() override;

    virtual void print(std::ostream& out) const override;

    virtual void operator*() override
    {
        for (int i = 0; i < 4; ++i)
            Virus::operator*();
    }
};

#endif // MIMIVIRUS_H