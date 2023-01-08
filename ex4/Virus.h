#ifndef VIRUS_H
#define VIRUS_H

#include <iostream>
#include <string>

class Virus
{
    int size;
    int* genome;
    std::string name;
    int variant = 0;

  public:
    Virus() = delete;
    Virus(const std::string& name, int* genome, int size);
    Virus(const std::string& name,
          int* genome,
          int size,
          int variant,
          int mutations);
    virtual ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);

    std::string getName() const { return name; }
    int getNum(int n) const;
    int getSize() const { return size; }
    int getVariant() const { return variant; }

    void setVariant(int variant);
    void setName(const std::string& name) { this->name = name; }

    int operator[](int n) const { return getNum(n); }
    virtual void operator*();
    virtual void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Virus& virus);
};

#endif // VIRUS_H