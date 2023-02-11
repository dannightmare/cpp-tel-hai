#pragma once

#define LOG(x) std::cout << x << std::endl

#include <iostream>
#include <string>

class Virus
{
    int m_size;
    int* m_genome;
    const std::string* m_name;
    int m_variant = 0;

  public:
    Virus() = delete;
    Virus(const std::string* name, int* genome, int size);
    Virus(const std::string* name,
          int* genome,
          int size,
          int variant,
          int mutations);
    virtual ~Virus();
    Virus(Virus& other);
    Virus& operator=(Virus& other);
    Virus(Virus&& other);
    Virus& operator=(Virus&& other);

    const std::string* getName() const { return m_name; }
    int getNum(int n) const;
    int getSize() const { return m_size; }
    int getVariant() const { return m_variant; }

    void setVariant(int variant);
    void setName(const std::string* name) { this->m_name = name; }

    int operator[](int n) const { return getNum(n); }
    virtual void operator*();
    virtual void print(std::ostream& out) const;

    friend std::ostream& operator<<(std::ostream& out, const Virus& virus);
};
class Lentivirus : public Virus
{
  public:
    Lentivirus() = delete;
    Lentivirus(const std::string* name, int* genome, int viruslength);
    Lentivirus(Virus& other);
    ~Lentivirus() override {}

    virtual void print(std::ostream& out) const override;

    virtual void operator*() override
    {
        for (int i = 0; i < 2; ++i)
            Virus::operator*();
    }
};
class Mimivirus : public Virus
{
  public:
    Mimivirus() = delete;
    Mimivirus(const std::string* name, int* genome, int viruslength);
    Mimivirus(Virus& other);
    ~Mimivirus() override;

    virtual void print(std::ostream& out) const override;

    virtual void operator*() override
    {
        for (int i = 0; i < 4; ++i)
            Virus::operator*();
    }
};

class Papilloma : public Virus
{

  public:
    Papilloma() = delete;
    Papilloma(const std::string* name, int* genome, int viruslength);
    Papilloma(Virus& other);
    ~Papilloma() override;

    virtual void print(std::ostream& out) const override;

    virtual void operator*() override { Virus::operator*(); }
};