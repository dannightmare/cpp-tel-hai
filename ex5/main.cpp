#include "Graph.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

vector<string>
getAllDestinations(Graph& gr, string& s);

int
main(int argc, char* argv[])
{

    Graph gr;
    string source;
    string destin;
    int weight;
    string of("output.dat");
    std::ifstream f;

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-o") {
            if (++i >= argc) {
                std::cerr << "no file after -o flag" << std::endl;
                exit(i);
            }
            of = argv[++i];
            continue;
        }

        f.open(argv[i]);
        if (!f) {
            std::cerr << "ERROR: " + string(argv[i]) +
                           " does not exist or cannot be opened"
                      << std::endl;
            exit(i);
        }
        f >> source;
        f >> destin;
        f >> weight;
        f.close();
        try {
            gr.addEdge(source, destin, weight);
        } catch (short) {
            std::cerr << "ERROR: node definition in " + string(argv[i]) +
                           " is invalid"
                      << std::endl;
        }
    }

    {
        std::ofstream outf(of);
        gr.print(outf);
        outf.close();
    }
    std::ostream_iterator<string> oit(std::cout, "\t");

    while (true) {
        string choice;
        std::cin >> choice;
        if (choice == "exit") {
            break;
        }
        vector<string> linksfrom;
        try {
            linksfrom = getAllDestinations(gr, choice);

            // std::cout << choice << '\t';
            if (linksfrom.size() == 1) {
                std::cout << choice << " : no outbound travel";
            } else {
                std::copy(linksfrom.begin(), linksfrom.end() - 1, oit);
                std::cout << linksfrom.back();
            }
            std::cout << std::endl;
        } catch (string e) {
            std::cout << e << std::endl;
        }
    }
    std::cout << "USAGE: <node> or ‘exit’ to terminate" << std::endl;

    /*
    std::ostream_iterator<string> oit(cout, ", ");
    try {
        gr.addVertex("hello");
        // gr.addVertex("hello");
        gr.addVertex("world");
        // gr.removeVertex("waarld");
        gr.updateEdge("hello", "world", 5);
        vector<string> con = gr.AllConnectedFrom("world");
        std::copy(con.begin(), con.end(), oit);
        vector<string> con2 = gr.AllConnectedTo("world");
        std::copy(con2.begin(), con2.end(), oit);
        // cout << gr.AreAdjacent("hello", "world") << endl;
        // cout << gr.removeEdge("hello", "world") << endl;
        // cout << gr.getWeight("hello", "world") << endl;

        // gr.removeVertex("hello");
        // gr.removeEdge("hello", "world");

    } catch (string s) {
        cout << s << endl;
    }
    */
    return 0;
}

bool
contains(const vector<string>& vec, string& s);

vector<string>
getAllDestinations(Graph& gr, string& is)
{
    vector<string> visited;
    vector<string> runner;
    runner.push_back(is);
    while (!runner.empty()) {
        string cur = runner.front();
        runner.erase(runner.begin());
        if (contains(visited, cur))
            continue;
        visited.push_back(cur);
        for (string s : gr.AllConnectedFrom(cur)) {
            runner.push_back(s);
        }
    }
    return visited;
}

bool
contains(const vector<string>& vec, string& s)
{
    for (string str : vec) {
        if (str == s)
            return true;
    }
    return false;
}