#include <iostream>
#include <string>

#ifndef VIRUS_H
#define VIRUS_H

class Virus
{
    int size;
    int* genome;
    std::string name;
    int variant = 0;
    int mutations;

  public:
    Virus() = delete;
    Virus(const std::string& name, int* genome, int size);
    Virus(const std::string& name,
          int* genome,
          int size,
          int variant,
          int mutations);
    ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);

    std::string getName() const;
    int getNum(int n) const;
    int getSize() const { return size; }
    
    void setVariant(int variant);

    int operator[](int n) const { return getNum(n); }
    void operator*();

    friend std::ostream& operator<<(std::ostream& out, const Virus& virus);
};

#endif // VIRUS_H