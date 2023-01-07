#include "Culture.h"

Culture::Culture(const std::string* names,
                 int** matrix,
                 int virusesamount,
                 int viruslength,
                 Virus* target,
                 int mutations)
  : viruslength(viruslength)
  , virusesamount(virusesamount)
  , mutations(mutations)
{
    if (this->target == nullptr) {
        this->target = new Virus(*target);
    }

    variants = new int[viruslength];
    this->names = new std::string[viruslength];
    viruses = new Virus*[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        variants[i] = 0;
        this->names[i] = names[i];
        viruses[i] = new Virus(names[i], matrix[i], viruslength);
    }
    sort();
}

Culture::~Culture()
{
    for (int i = 0; i < virusesamount; i++) {
        delete viruses[i];
    }
    delete[] viruses;
    delete target;
    delete[] names;
    delete[] variants;
}

Virus&
Culture::getVirus(int i)
{
    if (i < 0 || i >= virusesamount) {
        std::cerr << "getVirus index out of bounds " << i << std::endl;
        exit(8);
    }
    return *viruses[i];
}

Virus&
Culture::operator[](int i)
{
    return getVirus(i);
}

void
Culture::operator++(int)
{
    for (int i = 0; i < virusesamount; i++) {
        for (int j = 0; j < mutations; j++)
            *(*viruses[i]);
    }

    sort();
    *viruses[virusesamount - 1] = variant(*viruses[0]);
}

void
Culture::sort()
{
    double factor[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        factor[i] = calculate_factor(*target, *viruses[i]);
    }

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
}

double
Culture::calculate_factor(const Virus& virus1, const Virus& virus2)
{
    double countmisfits = 0;
    int viruslength = virus1.getSize();
    for (int i = 0; i < viruslength; i++) {
        if (virus1[i] == virus2[i])
            countmisfits++;
    }

    return 1 - (countmisfits / viruslength);
}

Virus&
Culture::variant(Virus& virus)
{
    // find which variant is next
    std::string name = virus.getName();
    int variant = 0;
    for (int i = 0; i < viruslength; i++) {
        if (name.compare(names[i]) == 0) {
            variant = ++(variants[i]);
        }
    }

// #define DEBUG_VARIANT
#ifdef DEBUG_VARIANT
    std::cout << "debug: Culture::variant(): variant=" << variant << std::endl;
#endif // DEBUG_VARIANT

    // create a new virus with the new variant

    Virus* virus_ret = new Virus(virus);

    virus_ret->setVariant(variant);
    return *virus_ret;
    // and return it

    // the variant table should be updated
}

bool
operator<(const Virus& virus1, const Virus& virus2)
{
    return Culture::calculate_factor(virus1, *Culture::target) <
           Culture::calculate_factor(virus2, *Culture::target);
}