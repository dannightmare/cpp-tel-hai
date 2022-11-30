//
// Created by Daniel Kusai on 19/11/2022.
//

#ifndef CPP_EX1_OBSERVATIONNODE_H
#define CPP_EX1_OBSERVATIONNODE_H

#include <string>

/**
 * behaves like a node for the current assignment
 *
 * implements the name next and vector of the observationNode
 * as well as assignments of them.
 */
class ObservationNode {
public:
    ObservationNode() = delete;

    ObservationNode(std::string name, double *vector);

    ObservationNode *getNext() const;

    void setNext(ObservationNode *next);

    ~ObservationNode();

    bool hasNext() const;

    const std::string &getName() const;

    void setName(const std::string &name);

    double *getVector() const;

    void setVector(double *vector);

private:
    ObservationNode *next = nullptr;
    std::string name;
    double *vector;

};


#endif //CPP_EX1_OBSERVATIONNODE_H
