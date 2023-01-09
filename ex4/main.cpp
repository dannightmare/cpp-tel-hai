#include "Culture.h"
#include "Lentivirus.h"
#include "Mimivirus.h"
#include "Papilloma.h"
#include "Virus.h"
#include <fstream>
#include <iostream>
#include <sstream>

const int MAXITERATIONS = 1000000;
const int MAXVIRUSES = 10000;
const int MINVIRUSES = 2;
const int MAXVIRUSLENGTH = 100;
const int MINVIRUSLENGTH = 5;

// config file
int viruslength = 0;
int mutations = 0;
Virus* target = nullptr;

// first generation file
int virusesamount = 0;
Culture* culture = nullptr;

// after finishing setup
int totaliterations = 0;

int*
string_to_vector(const std::string& str);

int
main(int argc, char** argv)
{
    // int x = 0, y = 2, z = 10, w = 5;
    // Queue<int>* queue = new Queue<int>();
    // queue->Enqueue(x);
    // queue->Enqueue(y);
    // queue->Enqueue(z);
    // queue->Enqueue(w);
    // std::cout << x << std::endl;
    // x = 4;
    // std::cout << queue->Dequeue() << std::endl;
    // queue->Dequeue();
    // queue->Dequeue();
    // queue->Dequeue();
    // queue->Dequeue();
    // queue->Enqueue(x);
    // std::cout << queue->Dequeue() << std::endl;
    // queue->sort();
    // queue->clear();
    // std::cout << *queue << std::endl;
    // return 0;

    if (argc != 3) {
        std::cerr
          << "Usage: run the program with <init file name> <location file name>"
          << std::endl;
        exit(1);
    }

    std::ifstream config(argv[1]);
    if (config.fail()) {
        std::cerr << "Failed to open configuration file " << argv[1]
                  << std::endl;
        exit(2);
    }
    std::ifstream first_generation(argv[2]);
    if (!first_generation) {
        std::cerr << "Failed to open first generation file " << argv[2]
                  << std::endl;
        exit(3);
    }

    std::string tmp;

    ////////////////////////////////////////////////////////////////
    /// read from configuration file

    config >> viruslength;
    if (viruslength < MINVIRUSLENGTH || viruslength > MAXVIRUSLENGTH) {
        std::cerr << "virus length is inappropriate" << std::endl;
        exit(4);
    }

    std::getline(config, tmp); // discard end of line
    std::getline(config, tmp);

    int* v = string_to_vector(tmp);
    target = new Virus("target", v, viruslength);
    Culture::setTarget(target);

    delete v;

    ////////////////////////////////////////////////////////////////
    /// read from first generation file

    first_generation >> virusesamount;
    std::getline(first_generation, tmp);
    if (virusesamount < 2) {
        std::cerr << "virusesamount too small" << std::endl;
        exit(7);
    }

    // Create culture

    culture = new Culture(virusesamount, viruslength);

    std::string name;
    char type;
    for (int i = 0; i < virusesamount; i++) {
        first_generation >> type;
        first_generation >> name;
        std::getline(first_generation, tmp);
        Virus* vir = nullptr;
        switch (type) {
            case 'P':
                vir = new Papilloma(name, string_to_vector(tmp), viruslength);
                break;
            case 'M':
                vir = new Mimivirus(name, string_to_vector(tmp), viruslength);
                break;
            case 'L':
                vir = new Lentivirus(name, string_to_vector(tmp), viruslength);
                break;
            default:
                exit(202);
        }
        culture->add(vir);
    }
    culture->sort();

    // std::cout << "input iterations: ";
    std::cin >> totaliterations;

    ////////////////////////////////////////////////////////////////
    /// FINISHED SETUP

    Virus* bestvirus = &culture->getBestVirus();
    double bestvirusfactor =
      culture->calculate_factor(*target, culture->getBestVirus());

    for (int i = 0; i < totaliterations; i++) {
        (*culture)++;

        double newfactor =
          culture->calculate_factor(*target, culture->getBestVirus());

        if (newfactor < bestvirusfactor) {
            bestvirusfactor = newfactor;
            bestvirus = &culture->getBestVirus();
            // delete bestvirus;
            // std::cout << "debug: [" << std::endl
            //           << typeid(culture->getBestVirus()).name() << std::endl
            //           << typeid(Papilloma).name() << std::endl
            //           << typeid(Mimivirus).name() << std::endl
            //           << typeid(Lentivirus).name() << std::endl
            //           << "]" << std::endl;
            // if (typeid(culture->getBestVirus()) == typeid(Papilloma&)) {
            //     bestvirus = new Papilloma(culture->getBestVirus());
            // } else if (typeid(culture->getBestVirus()) == typeid(Mimivirus&)) {
            //     bestvirus = new Mimivirus(culture->getBestVirus());
            // } else if (typeid(culture->getBestVirus()) == typeid(Lentivirus&)) {
            //     bestvirus = new Lentivirus(culture->getBestVirus());
            // }
        }
        if (newfactor == 0)
            break;
    }

    std::cout << (*culture) << std::endl;

    std::cout << *bestvirus << std::endl;

    ////////////////////////////////////////////////////////////////
    /// DELETE EVERYTHING

    delete target;
    delete culture;

    return 0;
}

int*
string_to_vector(const std::string& str)
{
    std::stringstream ss(str);
    int* v = new int[viruslength];

    for (int i = 0; i < viruslength; i++) {
        if (ss.eof()) {
            std::cerr << "Invalid input." << std::endl;
            exit(5);
        }
        ss >> v[i];
    }
    if (!ss.eof()) {
        std::cerr << "Invalid input." << std::endl;
        exit(6);
    }
    return v;
}
