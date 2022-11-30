#include <iostream>
#include "SquareMat.h"

int main() {
    SquareMat mat1(9);
    mat1.compare(SquareMat(9));
    // 2
    // works because SquareMat(9) creates an rval matrix which gets destroyed after comparison
    // and compare takes a const matrix which allows it to compare since the program
    // knows you aren't going to access the temporary memory

    //3
    SquareMat *matrixes[5];
    std::srand(time(nullptr));
    for (int i = 0; i < 5; i++) {
        matrixes[i] = new SquareMat(std::rand() % 40);
        std::cout << matrixes[i]->size() << std::endl;
    }
    SquareMat *min = matrixes[0];
    for (int i = 1; i < 5; i++) {
        if (matrixes[i]->compare(*min)) min = matrixes[i];
    }
    int sum = 0;
    for (int i = 0; i < min->size(); i++) {
        for (int j = 0; j < min->size(); j++) {
            sum += min->at(i, j);
        }
    }
    std::cout << sum << std::endl;

    SquareMat copyof0(*matrixes[0]);
    copyof0 = *min;

    return 0;
    /// change
}
