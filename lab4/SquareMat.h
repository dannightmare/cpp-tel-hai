//
// Created by Daniel Kusai on 22/11/2022.
//

#ifndef CPP_LAB4_SQUAREMAT_H
#define CPP_LAB4_SQUAREMAT_H


class SquareMat {
private:
    int ndim;
    int **data = nullptr;

    void initArray();

    void fillRand();

    int sumMat(int **data) const;

public:
    SquareMat(int dim);

    SquareMat(SquareMat const &cpy);

    SquareMat &operator=(SquareMat const &rhs);

    ~SquareMat();

    int size() const { return ndim; }

    int at(int i, int j) const;

    void print() const;

    bool compare(const SquareMat &other) const;

};


#endif //CPP_LAB4_SQUAREMAT_H
