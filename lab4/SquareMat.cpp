//
// Created by Daniel Kusai on 22/11/2022.
//

#include "SquareMat.h"
#include <iostream>

SquareMat::SquareMat(int dim) : ndim(dim) {
    if (ndim < 0) ndim = 0;
    initArray();
    fillRand();
    std::cout << "C'tor\n";
}

SquareMat::SquareMat(const SquareMat &cpy) : ndim(cpy.ndim) {
    initArray();
    *this = cpy;
    std::cout << "Copy C'tor\n";
}

void SquareMat::initArray() {
    if(data != nullptr) {
        for(int i = 0; i < ndim; i++) delete data[i];
        delete [] data;
    }
    data = new int *[ndim];
    for (int i = 0; i < ndim; i++) data[i] = new int[ndim];
}

SquareMat &SquareMat::operator=(const SquareMat &rhs) {
    if (this == &rhs) {
        return *this;
    }
    ndim = rhs.ndim;
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            data[i][j] = rhs.data[i][j];
        }
    }
    std::cout << "operator=\n";
    return *this;
}

SquareMat::~SquareMat() {
    for (int i = 0; i < ndim; i++) {
        delete[] data[i];
    }
    delete[] data;
    std::cout << "d'tor\n";
}

int SquareMat::at(int i, int j) const {
    if (i < 0 || i >= ndim || j < 0 || j >= ndim) return -1;
    return data[i][j];
}

void SquareMat::fillRand() {
    std::srand(time(nullptr));
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            data[i][j] = std::rand() % 900 + 100;
        }
    }
}

void SquareMat::print() const {
    std::cout << "[\n";
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "]\n";
}

bool SquareMat::compare(const SquareMat &other) const {
    return sumMat(this->data) < sumMat(other.data);
}

int SquareMat::sumMat(int **data) const {
    int sum = 0;
    for (int i = 0; i < ndim; i++) {
        for (int j = 0; j < ndim; j++) {
            sum += data[i][j];
        }
    }
    return sum;
}
