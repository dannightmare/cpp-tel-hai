//
// Created by Daniel Kusai on 19/11/2022.
//

#include "ObservationNode.h"

#ifndef CPP_EX1_OBSERVATIONCLI_H
#define CPP_EX1_OBSERVATIONCLI_H

/*
 * This class doubles as a LinkedList and as a CLI for the assignment.
 *
 * upon creation, it starts the program, and is the interface with the user.
 */
class ObservationCLI {
public:
    /*
     * don't need the default constructor
     */
    ObservationCLI() = delete;

    /*
     * the only constructor I will use
     */
    ObservationCLI(int maxsize, int dimension);

    ~ObservationCLI();

private:

    /*
     * this is called from the constructor to begin the program
     */
    void init();

    /**
     * this is called when the user chooses [1]
     */
    void newObservation();

    /**
     * this is called when the user calls [2]
     */
    void printObservation();

    /**
     * this is called when the user calls [3]
     */
    void printMean();

    /**
     * this is called when the user calls [4]
     */
    void printCovarianceMatrix();


    /**
     * prevents edge case where head is null,
     * I can simply go to head.getnext instead of checking if it is null
     */
    ObservationNode *head = new ObservationNode("", nullptr);


    // the maximum amount of vectors
    const int maxsize;
    // the vectors' dimension
    const int dimension;
    // a counter for the amount of observations
    int count = 0;

    /**
     * the linked list element of adding a new observation recursively
     * @param node
     * @param name
     * @param vector
     */
    void recAddElement(ObservationNode *node, std::string name, double *vector);

    /**
     * a helper function that takes a name and returns the vector
     * @param node
     * @param name
     * @return vector if there was a vector with the name found\n
     * or nullptr if there was no vector with the name
     */
    double *getElementByName(ObservationNode *node, std::string name);


    /**
     * a helper function that takes the name of the vector and the vector
     * and prints it according to what's asked
     * @param name
     * @param vector
     */
    void printVector(const std::string &name, const double *vector) const;

    /**
     *
     * @return double[][] array that is the covariance matrix
     */
    double **getCovarianceMatrix();

    /**
     *
     * @return mean vector
     */
    double *getMean() const;
};


#endif //CPP_EX1_OBSERVATIONCLI_H
