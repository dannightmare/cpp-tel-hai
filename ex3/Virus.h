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

    double calculate_factor(const Virus& other);
    Virus& variant();
    std::string getName() const;

    void operator*();

    friend std::ostream& operator<<(std::ostream & out, const Virus& virus);
};

#endif // VIRUS_H