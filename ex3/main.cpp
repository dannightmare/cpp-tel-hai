#include "Culture.h"
#include "Virus.h"
// #include <cstddef>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

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

#define DEBUG

int*
string_to_vector(const std::string str);

int
main(int argc, char** argv)
{
    if (argc < 2) {
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
    config >> viruslength >> mutations;
    if (viruslength < MINVIRUSLENGTH || viruslength > MAXVIRUSLENGTH) {
        std::cerr << "virus length is inappropriate" << std::endl;
        exit(4);
    }

    std::getline(config, tmp);
    std::getline(config, tmp);

#ifdef DEBUG
    std::cout << "viruslength=" << viruslength << std::endl;
    std::cout << "mutations=" << mutations << std::endl;
    std::cout << "tmp=" << tmp << std::endl;
#endif // DEBUG

    int* v = string_to_vector(tmp);
    target = new Virus("target", v, viruslength);

#ifdef DEBUG
    for (int i = 0; i < viruslength; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
#endif // DEBUG
    delete v;

    first_generation >> virusesamount;
    std::getline(first_generation, tmp);
    if (virusesamount < 2) {
        std::cerr << "virusesamount too short" << std::endl;
        exit(7);
    }

    int* matrix[virusesamount];
    std::string names[virusesamount];
    for (int i = 0; i < virusesamount; i++) {
        first_generation >> names[i];
        std::getline(first_generation, tmp);
        matrix[i] = string_to_vector(tmp);
    }

#ifdef DEBUG
    std::cout << "matrix:" << std::endl;
    for (int i = 0; i < virusesamount; i++) {
        for (int j = 0; j < viruslength; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif // DEBUG

    // std::string str;
    // getline(std::cin, str);
    // std::cout << rand() << " " << rand();

    // std::cin >> str;
    // std::cout << std::endl << str << std::endl;


    /// DELETE EVERYTHING
    delete target;
    delete culture;

    for (int i = 0; i < virusesamount; i++) {
        delete[] matrix[i];
    }
    return 0;
}

int*
string_to_vector(const std::string str)
{
    std::stringstream ss(str);
    int* v = new int[viruslength];
    for (int i = 0; i < viruslength; i++) {
        if (ss.eof()) {
            std::cerr << "Vector too short" << std::endl;
            exit(5);
        }
        ss >> v[i];
    }
    if (!ss.eof()) {
        std::cerr << "Vector too long" << std::endl;
        exit(6);
    }
    return v;
}
