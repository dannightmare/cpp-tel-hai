#include <iostream>
#include <string>
#include "Alchemize.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid run arguments; run the game with board size.\n";
        exit(2);
    }
    try
    {
        Alchemize(stoi(argv[1]));
    }
    catch (const invalid_argument &ia)
    {
        cerr << "Invalid Argument: " << ia.what() << endl;
        exit(1);
    }

    // this is how it will be used
    // Item *i = new Potion();


    return 0;
}