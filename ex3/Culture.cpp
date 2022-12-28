#include "Culture.h"

Culture::Culture(const std::string* names,
                 int** matrix,
                 int virusesamount,
                 int viruslength,
                 Virus* target,
                 int mutations)
  : virusesamount(virusesamount)
  , viruslength(viruslength)
  , target(new Virus(*target))
  , mutations(mutations)
{
    viruses = new Virus*[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        viruses[i] = new Virus(names[i], matrix[i], viruslength);
        std::cout << "debug: Culture c'tor virus pointer: " << viruses[i] << std::endl;
    }
    sort();
}

Culture::~Culture()
{
    std::cout << "debug: started deletion of culture " << std::endl;

    for (int i = 0; i < virusesamount; i++) {
        std::cout << viruses[i] << std::endl;
        delete viruses[i];
    }
    std::cout << "debug: deleted viruses" << std::endl;
    delete[] viruses;
    delete target;
}

Virus&
Culture::getVirus(int i)
{
    std::cout << "debug: Culture::getVirus(int i): " << i << std::endl;
    if (i < 0 || i >= virusesamount) {
        std::cerr << "getVirus index out of bounds " << i << std::endl;
        exit(8);
    }
    return *viruses[i];
}

Virus&
Culture::operator[](int i)
{
    std::cout << "debug: Culture::operator[](int i) = " << i << std::endl;
    return getVirus(i);
}

void
Culture::operator++(int)
{
    std::cout << "debug: Culture::operator++(int)" << std::endl;
    for (int i = 0; i < virusesamount; i++) {
        std::cout << "debug: Culture::operator++: iter " << i << std::endl;
        for (int j = 0; j < mutations; j++)
            *(*viruses[i]);
    }

    sort();
    *viruses[virusesamount - 1] = viruses[0]->variant();
}

void
Culture::sort()
{
    double factor[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        factor[i] = target->calculate_factor(*viruses[i]);
    }
#define DEBUG_FACTOR
#ifdef DEBUG_FACTOR
    for (int i = 0; i < virusesamount; i++) {
        std::cout << "debug: Culture::sort: factor=" << factor[i] << std::endl
                  << std::endl;
    }
#endif // DEBUG_FACTOR

    for (int i = 1; i < virusesamount; i++) {
        double cur = factor[i];
        Virus curv(*viruses[i]);
        int j = 0;
        for (j = i - 1; j >= 0 && cur < factor[j]; j--) {
            factor[j + 1] = factor[j];
            *viruses[j + 1] = *viruses[j];
        }
        j++;
        factor[j] = cur;
        *viruses[j] = curv;
    }

#ifdef DEBUG_FACTOR
    for (int i = 0; i < virusesamount; i++) {
        std::cout << "debug: Culture::sort: factor=" << factor[i] << std::endl;
    }
#endif // DEBUG_FACTOR
}
