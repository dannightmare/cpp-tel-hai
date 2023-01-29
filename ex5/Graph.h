#ifndef GRAPH_H
#define GRAPH_H

// #include <set>
// using std::set;
#include <vector>
#include <iostream>
// using std::cout;

// using std::endl;
using std::string;
using std::vector;


// template<class V, class E>
class Graph
{
    vector<vector<int>> edges;
    vector<string> vert;

    int getIndex(const string&) const;

  public:
    void addVertex(const string& v1);
    void removeVertex(const string& v1);

    void addEdge(const string& v1, const string& v2, int weight);
    int removeEdge(const string& v1, const string& v2);
    void updateEdge(const string& v1, const string& v2, int weight);

    int getWeight(const string& v1, const string& v2) const;

    bool AreAdjacent(const string& v1, const string& v2) const;

    vector<string> AllConnectedFrom(const string& v) const;
    vector<string> AllConnectedTo(const string& v) const;

    void print(std::ostream& os) const;
};

#endif // GRAPH_H