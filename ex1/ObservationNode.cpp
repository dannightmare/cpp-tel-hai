//
// Created by Daniel Kusai on 19/11/2022.
//

#include "ObservationNode.h"

ObservationNode::ObservationNode(std::string name, double *vector) : name(name), vector(vector) {
    next = nullptr;
}

ObservationNode *ObservationNode::getNext() const {
    return next;
}

void ObservationNode::setNext(ObservationNode *next) {
    ObservationNode::next = next;
}

ObservationNode::~ObservationNode() {
    delete next;
    delete vector;

}

bool ObservationNode::hasNext() const {
    return next != nullptr;
}

const std::string &ObservationNode::getName() const {
    return name;
}

void ObservationNode::setName(const std::string &name) {
    ObservationNode::name = name;
}

double *ObservationNode::getVector() const {
    return vector;
}

void ObservationNode::setVector(double *vec) {
    delete this->vector;
    vector = vec;
}