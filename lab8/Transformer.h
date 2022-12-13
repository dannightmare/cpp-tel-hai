#include "Robot.h"

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

class Transformer : public Robot
{
  public:
    Transformer();
    ~Transformer();
    Transformer& operator=(const Transformer& other);
    Transformer(const Transformer& other);

    char getLetter() const override { return is_flying ? '>' : 'F'; }
    void move(std::string& str) override;

  private:
    bool is_flying;
    void transform();
};

#endif // TRANSFORMER_H