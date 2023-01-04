#include "Robot.h"
#include "Transformer.h"
#include <fstream>
#include <iostream>
int
main()
{
    std::string st[4];
    std::ifstream file;
    file.open("tracks.txt");
    if (file.fail()) {
        std::cout << "Error: Could not open tracks.txt" << std::endl;
        return -1;
    }
    std::string s[4];
    getline(file, s[0]);
    getline(file, s[1]);
    getline(file, s[2]);
    getline(file, s[3]);

    Robot r;
    Transformer f;

    while (true) {

        // I want to clear the screen according to system
        // AUTOTEST: doesn't like this
        // #if defined(__APPLE__) || defined(__linux__)
        //     system("clear");
        // #elif defined(_WIN32) || defined(_WIN64)
        //     system("cls");
        // #endif // __APPLE__
        r.move(s[0]);
        f.move(s[1]);

        if (r.getLocation() >= s[0].length()) {
            std::cout << "Robot won" << std::endl;
            break;
        }
        if (f.getLocation() >= s[1].length()) {
            std::cout << "Transformer won" << std::endl;
            break;
        }
    }

    std::cout << s[2] << std::endl;
    std::cout << s[3] << std::endl;
    file.close();
    return 0;
}
