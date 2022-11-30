//
// Created by Daniel Kusai on 19/11/2022.
//
#include <iostream>
#include "ObservationCLI.h"

using namespace std;

ObservationCLI::ObservationCLI(const int maxsize, const int dimension) : maxsize(maxsize), dimension(dimension) {
    init();
}

void ObservationCLI::init() {
    string choice = "";

    cout << "[1] New observation\n"
            "[2] Print observation\n"
            "[3] Expected value vector\n"
            "[4] Covariance matrix\n"
            "[5] Exit\n";

    while (true) {
        cin >> choice;
//        cout<<choice<<endl;
        if (choice.length() > 1) {
            cerr << "Invalid option.\n";
            continue;
        }
//        if (choice.length() < 1) continue;

        switch (choice.at(0)) {
            case '1':
                newObservation();
                break;
            case '2':
                printObservation();
                break;
            case '3':
                printMean();
                break;
            case '4':
                printCovarianceMatrix();
                break;
            case '5':
                return;
            default:
                cerr << "Invalid option.\n";
        }
    }
}

// [1]
void ObservationCLI::newObservation() {
    string name = "", values = "";
    auto *vector = new double[dimension];
    int next_space = 0;
    unsigned int prev_space = 0;
    cout << "Enter observation name:\n";
    cin >> name;
    cout << "Enter observation values:\n";
    getchar();
    getline(cin, values);

    for (int i = 0; i < dimension; i++) {
        // if prev_space passes length, there aren't enough entries
        if (values.length() <= prev_space) {
            cerr << "Invalid observation.\n";
            return;
        }
        // if next_space is -1 here it means I didn't reach the end of i
        if(next_space == -1) {
            cerr<<"Invalid observation.\n";
            return;
        }
        // note that if there is an extra space on input after the numbers it still calls invalid observation.
        next_space = (int) values.find_first_of(' ', prev_space);
        try {
            vector[i] = stod(values.substr(prev_space, next_space));
        } catch (std::invalid_argument) {
            cerr << "Invalid observation.\n";
            return;
        }

        prev_space = next_space + 1;
    }

    // if next_space isn't -1 there were more entries later and I don't allow it
    if (next_space != -1) {
        cerr << "Invalid observation.\n";
        return;
    }

    // vector can't be nullptr at this point
    recAddElement(head, name, vector);
}

void ObservationCLI::recAddElement(ObservationNode *node, string name, double *vector) {
    if (node->getName() == name) {
        node->setVector(vector);
        return;
    }
    if (!node->hasNext()) {
        if (count >= maxsize) {
            cerr << "reached maxsize\n";
            return;
        }
        node->setNext(new ObservationNode(std::move(name), vector));
        this->count++;
        return;
    }
    recAddElement(node->getNext(), name, vector);
}

// [2]
void ObservationCLI::printObservation() {
    string name = "";
    double *vector = nullptr;
    cout << "Enter observation name:\n";
    cin >> name;
    vector = getElementByName(head, name);
    if (!vector) {
        cerr << "Invalid or nonexistent observation.\n";
        return;
    }
    printVector(name, vector);
}


double *ObservationCLI::getElementByName(ObservationNode *node, string name) {
    if (!node) return nullptr;
    if (node->getName() == name) return node->getVector();
    return getElementByName(node->getNext(), name);
}

// [3]
void ObservationCLI::printMean() {
    if (count == 0) {
        cerr << "Empty calculator.\n";
        return;
    }
    double *mean = getMean();
    printVector("mean", mean);
}

double *ObservationCLI::getMean() const {
    auto *mean = new double[dimension];
    const double *vector = nullptr;
    ObservationNode *node = head->getNext();

    while (node) {
        vector = node->getVector();
        for (int i = 0; i < dimension; i++) {
            mean[i] += vector[i];
        }
        node = node->getNext();
    }
    for (int i = 0; i < dimension; i++) {
        mean[i] /= count;
    }
    return mean;
}

// [4]
void ObservationCLI::printCovarianceMatrix() {
    if (count == 0) {
        cerr << "Empty calculator.\n";
        return;
    }
    double **matrix = getCovarianceMatrix();

    cout << "cov = [\n";
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
    cout << "]";
}

double **ObservationCLI::getCovarianceMatrix() {

    double *mean = getMean();
    double *curVector = nullptr;
    double **covariance = new double *[dimension];
    ObservationNode *node = nullptr;
    double cov = 0;
    int M = count == 1 ? 1 : count - 1;

    for (int i = 0; i < dimension; i++) {
        covariance[i] = new double[dimension];
    }

    for (int i = 0; i < dimension; i++) {
        for (int j = i; j < dimension; j++) {
            node = head->getNext();
            cov = 0;
            while (node) {
                curVector = node->getVector();
                cov += (curVector[i] - mean[i]) * (curVector[j] - mean[j]);
                node = node->getNext();
            }
            cov /= M;
            covariance[i][j] = cov;
            covariance[j][i] = cov;
        }
    }

    return covariance;
}

void ObservationCLI::printVector(const string &name, const double *vector) const {
    cout << name << " = [";
    for (int i = 0; i < dimension; i++) {
        cout << " " << vector[i];
    }
    cout << "]\n";
}

ObservationCLI::~ObservationCLI() {
    delete head;
}