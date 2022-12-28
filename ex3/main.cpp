#include "Culture.h"
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

    config >> viruslength >> mutations;
    if (viruslength < MINVIRUSLENGTH || viruslength > MAXVIRUSLENGTH) {
        std::cerr << "virus length is inappropriate" << std::endl;
        exit(4);
    }

    std::getline(config, tmp);
    std::getline(config, tmp);

    int* v = string_to_vector(tmp);
    target = new Virus("target", v, viruslength);

    delete v;

    ////////////////////////////////////////////////////////////////
    /// read from first generation file

    first_generation >> virusesamount;
    std::getline(first_generation, tmp);
    if (virusesamount < 2) {
        std::cerr << "virusesamount too small" << std::endl;
        exit(7);
    }

    int* matrix[virusesamount];
    std::string names[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        first_generation >> names[i];
        std::getline(first_generation, tmp);
        matrix[i] = string_to_vector(tmp);
    }

    culture =
      new Culture(names, matrix, virusesamount, viruslength, target, mutations);
    // target = nullptr;

    // std::cout << "input iterations: ";
    std::cin >> totaliterations;

    ////////////////////////////////////////////////////////////////
    /// FINISHED SETUP

    Virus bestvirus((*culture)[0]);
    double bestvirusfactor = target->calculate_factor(bestvirus);

    for (int i = 0; i < totaliterations; i++) {
        (*culture)++;

        double newfactor = target->calculate_factor((*culture)[0]);
        if (newfactor == 0) {

            bestvirus = (*culture)[0];
            break;
        }
        if (newfactor < bestvirusfactor) {
            bestvirusfactor = newfactor;
            bestvirus = (*culture)[0];
        }
    }

    for (int i = 0; i < virusesamount; i++) {
        std::cout << (*culture)[i] << std::endl;
    }
    std::cout << std::endl << bestvirus << std::endl;

    ////////////////////////////////////////////////////////////////
    /// DELETE EVERYTHING

    delete target;
    delete culture;

    for (int i = 0; i < virusesamount; i++) {
        delete matrix[i];
    }

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
