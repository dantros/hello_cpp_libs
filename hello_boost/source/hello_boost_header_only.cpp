// Extracted from: https://www.boost.org/doc/libs/1_79_0/libs/graph/doc/adjacency_matrix.html

#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_utility.hpp>
#include <iostream>

int main()
{
    enum { A, B, C, D, E, F, N };
    const char* name = "ABCDEF";

    typedef boost::adjacency_matrix<boost::directedS> Graph;
    Graph g(N);
    add_edge(B, C, g);
    add_edge(B, F, g);
    add_edge(C, A, g);
    add_edge(C, C, g);
    add_edge(D, E, g);
    add_edge(E, D, g);
    add_edge(F, A, g);

    std::cout << "vertex set: ";
    boost::print_vertices(g, name);
    std::cout << std::endl;

    std::cout << "edge set: ";
    boost::print_edges(g, name);
    std::cout << std::endl;

    std::cout << "out-edges: " << std::endl;
    boost::print_graph(g, name);
    std::cout << std::endl;
}