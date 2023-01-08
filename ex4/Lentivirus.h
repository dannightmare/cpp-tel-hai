#ifndef LENTIVIRUS_H
#define LENTIVIRUS_H

#include "Virus.h"

class Lentivirus : public Virus
{
  public:
    Lentivirus() = delete;
    Lentivirus(std::string name, int* genome, int viruslength);

    virtual void operator*() override
    {
        for (int i = 0; i < 2; ++i)
            Virus::operator*();
    }
};

#endif // LENTIVIRUS_H