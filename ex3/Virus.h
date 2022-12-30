#include <iostream>
#include <string>

#ifndef VIRUS_H
#define VIRUS_H

class Virus
{

    int size;
    int* genome;
    std::string name;

  public:
    Virus() = delete;
    Virus(const std::string& name, int* genome, int size);
    ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);

    int operator[](int n) const;
    Virus& variant();
    std::string getName() const;
    int getNum(int n) const;

    void operator*();

    friend std::ostream& operator<<(std::ostream & out, const Virus& virus);
};

#endif // VIRUS_H