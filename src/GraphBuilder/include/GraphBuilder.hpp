#pragma once

#include "Graph.hpp"
#include "Randomizer.hpp"

class GraphBuilder {
    Randomizer random;

   public:
    Graph build_random_graph(int, int, int, int) const;
};