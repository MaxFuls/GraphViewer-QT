#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>

class Graph {
private:
    std::vector<std::pair<int, int>> vertexes;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<double>> distances;
    int radius;
    int min_edges_count;
    int max_edges_count;
protected:
    Graph(const std::vector<std::pair<int, int>>&,
          const std::vector<std::vector<int>>&,
          const std::vector<std::vector<double>>&,
          int, int, int);
public:
    Graph() = default;
    const std::vector<std::pair<int, int>>& get_vertexes() const;
    const std::vector<std::vector<int>>& get_edges() const;
    const std::vector<std::vector<double>>& get_distances() const;
    int get_radius() const;
    int get_min_edges_count() const;
    int get_max_edges_count() const;
    
    friend class GraphBuilder;
};

#endif