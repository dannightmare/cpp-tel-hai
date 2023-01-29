#include "Graph.h"
#include <string>

inline int
min(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return a < b ? a : b;
}

void
Graph::addVertex(const string& v1)
{
    if (v1 == "" || v1.find(' ') != string::npos || v1 == "exit") {
        throw short(1);
    }
    // check if vertex exists
    try {
        getIndex(v1);
        throw short(1);
    } catch (const string&) {
        // proceed everythin is good
    } catch (short) {
        throw v1 + " already exists";
    }

    // add vertex
    vert.push_back(v1);
    for (vector<int>& vs : edges) {
        vs.push_back(-1);
    }
    edges.push_back(vector<int>(vert.size(), -1));
    edges[edges.size() - 1][edges.size() - 1] = 0;
}

void
Graph::removeVertex(const string& v1)
{
    // find v1
    int i = getIndex(v1);

    // remove v1
    vert.erase(vert.begin() + i);
    edges.erase(edges.begin() + i);
    for (vector<int>& vs : edges) {
        vs.erase(vs.begin() + i);
    }
}

int
Graph::getIndex(const string& v) const
{
    int i = 0;
    for (i = 0; i < (int)vert.size(); ++i) {
        if (vert[i] == v) {
            break;
        }
    }
    if (i == (int)vert.size()) {
        throw v + " does not exist in the current network";
    }
    return i;
}

void
Graph::addEdge(const string& v1, const string& v2, int weight)
{
    if (weight <= 0)
        throw short(2);
    {
        try {
            addVertex(v1);
        } catch (string) {
        }
        try {
            addVertex(v2);
        } catch (string) {
        }
    }
    int row = getIndex(v1);
    int col = getIndex(v2);
    edges[row][col] = min(edges[row][col], weight);
}

int
Graph::removeEdge(const string& v1, const string& v2)
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    if (row == col) {
        throw "Can't update weight between " + v1 + " " + v2;
    }
    int weight = edges[row][col];
    edges[row][col] = -1;
    return weight;
}

void
Graph::updateEdge(const string& v1, const string& v2, int weight)
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    if (row == col) {
        throw "Can't update weight between " + v1 + " " + v2;
    }
    edges[row][col] = weight;
}

int
Graph::getWeight(const string& v1, const string& v2) const
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    int weight = edges[row][col];
    return weight;
}

bool
Graph::AreAdjacent(const string& v1, const string& v2) const
{
    int row = getIndex(v1);
    int col = getIndex(v2);
    return edges[row][col] != 0;
}

vector<string>
Graph::AllConnectedFrom(const string& v) const
{
    int row = getIndex(v);
    vector<string> connected;
    for (int i = 0; i < (int)vert.size(); ++i) {
        if (edges[row][i] > 0) {
            connected.push_back(vert[i]);
        }
    }
    return connected;
}

vector<string>
Graph::AllConnectedTo(const string& v) const
{
    int col = getIndex(v);
    vector<string> connected;
    for (int i = 0; i < (int)vert.size(); ++i) {
        if (edges[i][col] > 0) {
            connected.push_back(vert[i]);
        }
    }
    return connected;
}

void
Graph::print(std::ostream& os) const
{
    int i = 0;
    int j = 0;
    const int SIZE = vert.size();
// #define DEBUG_PRINT
#ifdef DEBUG_PRINT
    for (i = 0; i < SIZE; ++i) {
        for (j = 0; j < SIZE; ++j) {
            std::cout << edges[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif // DEBUG_PRINT

    for (i = 0; i < SIZE; ++i) {
        os << vert[i] << "\t";
        for (j = 0; j < SIZE; ++j) {
            if (edges[i][j] > 0) {
                os << vert[j] << " ";
            }
        }
        os << std::endl;
    }
}