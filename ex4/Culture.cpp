#include "Culture.h"

Culture::Culture(int virusesamount, int viruslength)
  : viruslength(viruslength)
  , virusesamount(virusesamount)
{
    variants = new int[viruslength];
    names = new std::string[viruslength];
}

Culture::~Culture()
{
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
    while (i > 0) {
        queue.Enqueue(queue.Dequeue());
        i--;
    }
    Virus* v = &queue.Peek();
    sort();
    return *v;
}

Virus&
Culture::operator[](int i)
{
    return getVirus(i);
}

Virus&
Culture::getBestVirus()
{
    return queue.Peek();
}

void
Culture::operator++(int)
{
    for (int i = 0; i < virusesamount; i++) {
        Virus v = queue.Dequeue();
        *v;
        queue.Enqueue(v);
    }

    sort();
    for (int i = virusesamount - 1; i > 0; i--) {
        Virus* v = &operator[](i);
        if (dynamic_cast<Papilloma*>(v)) {
            continue;
        }
        *v = variant(getBestVirus());
        break;
    }
}

void
Culture::sort()
{
    queue.sort();
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