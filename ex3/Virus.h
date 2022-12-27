#include <sstream>
#include <string>

#ifndef VIRUS_H
#define VIRUS_H

class Virus
{

    int size;
    int* genome;
    std::string name;

  public:
    Virus();
    Virus(const std::string& name, const std::string& vector);
    ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);
};

#endif // VIRUS_H