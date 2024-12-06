#include "Graph.hpp"

#include <vector>

Graph::Graph(const std::vector<std::pair<int, int>>& vertexes, const std::vector<std::vector<int>>& edges)
     : vertexes(vertexes), edges(edges) {}

const std::vector<std::vector<int>>& Graph::get_edges() const {
    return edges;
}

const std::vector<std::pair<int, int>>& Graph::get_vertexes() const {
    return vertexes;
}