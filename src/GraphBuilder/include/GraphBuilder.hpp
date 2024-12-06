#ifndef GRAPH_BUUILDER_HPP
#define GRAPH_BUUILDER_HPP

#include "Randomizer.hpp"
#include "Graph.hpp"

class GraphBuilder {
    Randomizer random;
public:
    Graph build_random_graph(int, int, int, int) const;
};

#endif