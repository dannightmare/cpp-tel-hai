//
// Created by daniku on 11/16/22.
//
#include <iostream>
#include "ObservationCLI.h"

using namespace std;


int main(int argc, char **argv) {
    // I have argv[2] vectors each of size argv[1]
    // NOT the total numbers
    // TODO: argc has to be 3 cerr << "Invalid arguments <int> <int>.\n"

    if (argc != 3) {
        cerr << "Invalid arguments <int> <int>.\n";
        exit(3);
    }

    ObservationCLI observationCli(stoi(argv[2]), stoi(argv[1]));


    /*
     * first print
     * "[1] New observation
     *  [2] Print observation
     *  ....
     * "
     * once and only at the start
     */

    // [1]

    // when getting the observation name,
    // if it already exists, I should rewrite the previous one

    // when getting the observation values, they have to be separated by spaces only " "
    // if I don't get the correct amount of numbers I don't save the observation
    // and print "Invalid observation.\n"


    // [2]

    // if name non existent print error to cerr

    // when printing, don't print the last space:
    // "mean = [ 1 2 3 4]"


    // [3]

    // average of all observations in the same index
    /*
     * so if I have observation a and b of size 3
     * then the average will be avg[0] = a[0] + b[0] / 2 and so forth for avg[1], avg[2]
     */


    // [4]

    // the matrix will be symmetrical so no need to calculate twice

    return 0;
}