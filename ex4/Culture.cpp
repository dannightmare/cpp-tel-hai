#include "Culture.h"
#include <exception>

Virus* Culture::target;

Culture::Culture(int virusesamount, int viruslength)
  : viruslength(viruslength)
  , virusesamount(virusesamount)
{
    variants = new int[viruslength];
    m_names = new const std::string*[viruslength];
}

Culture::~Culture()
{
    delete[] m_names;
    delete[] variants;
}

Virus*
Culture::getVirus(int i)
{
    if (i < 0 || i >= virusesamount) {
        std::cerr << "getVirus index out of bounds " << i << std::endl;
        exit(8);
    }
    int iter = 0;
    while (iter < i) {
        queue.Enqueue(queue.Dequeue());
        ++iter;
    }
    Virus* v = queue.Peek();
    while (iter < virusesamount) {
        queue.Enqueue(queue.Dequeue());
        ++iter;
    }
    // sort();
    return v;
}

Virus*
Culture::operator[](int i)
{
    return getVirus(i);
}

Virus&
Culture::getBestVirus()
{
    return *queue.Peek();
}

void
Culture::operator++(int)
{
    for (int i = 0; i < virusesamount; i++) {
        Virus* v = queue.Dequeue();
        **v;
        queue.Enqueue(v);
    }
    // getBestVirus(); but also create a new virus by type
    Virus* bestVirusVariant = &getBestVirus();
    if (typeid(*bestVirusVariant) == typeid(Papilloma)) {
        bestVirusVariant = new Papilloma(variant(*bestVirusVariant));
    } else if (typeid(*bestVirusVariant) == typeid(Mimivirus)) {
        bestVirusVariant = new Mimivirus(variant(*bestVirusVariant));
    } else if (typeid(*bestVirusVariant) == typeid(Lentivirus)) {
        bestVirusVariant = new Lentivirus(variant(*bestVirusVariant));
    }

    // std::cout << queue << std::endl;
    for (int i = virusesamount - 1; i > 0; i--) {
        Virus* v = operator[](i);
        if (dynamic_cast<Papilloma*>(v)) {
            continue;
        }
        // std::cout << queue << std::endl;
        remove(v);
        queue.Enqueue(bestVirusVariant);
        break;
    }
    // std::cout << queue << std::endl;

    sort();
}

/**
 * This function is so disgusting primarily because of the restriction
 * of having to use a Queue for such an unfitting task.
 * 
 * who thought to make us use a queue to implement what is essentially an array...
 */
void
Culture::remove(Virus* virus)
{
    int iter = virusesamount;
    while (virus->getVariant() != queue.Peek()->getVariant() ||
           virus->getName() != queue.Peek()->getName()) {
        queue.Enqueue(queue.Dequeue());
        if (iter-- < 0) {
            std::cerr << "ERROR: couldn't find the appropriate virus to remove"
                      << *virus << std::endl;
            exit(404);
        }
    }
    delete queue.Dequeue();
    sort();
}

void
Culture::sort()
{
    queue.sort();
}

double
Culture::calculate_factor(const Virus& virus1, const Virus& virus2)
{
    double countfit = 0;
    int viruslength = virus1.getSize();
    for (int i = 0; i < viruslength; i++) {
        if (virus1[i] == virus2[i])
            countfit++;
    }

    return 1 - (countfit / viruslength);
}

Virus&
Culture::variant(Virus& virus)
{
    // find which variant is next
    const std::string* name = virus.getName();
    int index = name - *m_names;
    // LOG(index);

    int variant = ++variants[index];

    // for (int i = 0; i < virusesamount; i++) {
    //     if (name.compare(names[i]) == 0) {
    //         variant = ++(variants[i]);
    //         break;
    //     }
    // }

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

void
Culture::setTarget(Virus* target)
{
    Culture::target = target;
}

// should only be called on setup
void
Culture::add(Virus* virus)
{
    m_names[queue.getSize()] = virus->getName();
    variants[queue.getSize()] = 0;
    queue.Enqueue(virus);
}

std::ostream&
operator<<(std::ostream& out, const Culture& culture)
{
    out << culture.queue;
    return out;
}