#include <string>
#include <sstream>

#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
  public:
    Virus();
    Virus(const std::string& name, const std::string& vector);
    ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);

    private:
    int size;
    int *vector;
    std::string name;
};

#endif // VIRUS_H