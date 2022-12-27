#include "Culture.h"
#include "Virus.h"
#include <cstddef>
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
int viruses = 0;
Culture* culture = nullptr;



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
    std::stringstream ss(tmp);

    // std::string str;
    // getline(std::cin, str);
    // std::cout << rand() << " " << rand();

    // std::cin >> str;
    // std::cout << std::endl << str << std::endl;

    return 0;
}