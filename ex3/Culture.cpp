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
    variants = new int[viruslength];
    names = new std::string[viruslength];
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
    *viruses[virusesamount - 1] = viruses[0]->variant();
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
Culture::calculate_factor(Virus& virus1, Virus& virus2)
{
    double countmisfits = 0;
    for (int i = 0; i < viruslength; i++) {
        if (virus1[i] == virus2[i])
            countmisfits++;
    }

    return 1 - (countmisfits / viruslength);
}

Virus&
Culture::variant(Virus& virus)
{
    /// TODO: finish this function, it was just moved from Virus.cpp
    std::string name = virus.getName(); // fixed this line already
    int underscore = name.find("_");

    if (underscore == -1) {
        name = name + "_1";
    } else {
        int variant = std::stoi(name.substr(underscore + 1));
        name = name.substr(0, underscore) + "_" + std::to_string(variant + 1);
    }

    Virus* virus = new Virus(*this);

    virus->name = name;
    return *virus;
}
