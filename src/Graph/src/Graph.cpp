#include "Graph.hpp"

#include <vector>

Graph::Graph(const std::vector<std::pair<int, int>>& vertexes,
             const std::vector<std::vector<int>>& edges, 
             const std::vector<std::vector<double>>& distances,
             int radius, int min_edges_count, int max_edges_count)
     : vertexes(vertexes), edges(edges), distances(distances), radius(radius),
       min_edges_count(min_edges_count), max_edges_count(max_edges_count) {}

const std::vector<std::vector<int>>& Graph::get_edges() const {
    return edges;
}

const std::vector<std::pair<int, int>>& Graph::get_vertexes() const {
    return vertexes;
}

const std::vector<std::vector<double>>& Graph::get_distances() const {
    return distances;
}

int Graph::get_radius() const {
    return radius;
}

int Graph::get_min_edges_count() const {
    return min_edges_count;
}
int Graph::get_max_edges_count() const {
    return max_edges_count;
}