#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>

class Graph {
private:
    std::vector<std::pair<int, int>> vertexes;
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> distances;
    std::vector<std::vector<std::pair<int, int>>> adj_table;
    std::vector<int> dists;
    std::vector<int> paths;
    int radius;
    int min_edges_count;
    int max_edges_count;
    void compute_path_and_dists();
protected:
    Graph(const std::vector<std::pair<int, int>>&,
          const std::vector<std::vector<int>>&,
          const std::vector<std::vector<int>>&,
          const std::vector<std::vector<std::pair<int, int>>>&,
          int, int, int);
public:
    Graph() = default;
    const std::vector<std::pair<int, int>>& get_vertexes() const;
    const std::vector<std::vector<int>>& get_edges() const;
    const std::vector<std::vector<int>>& get_distances() const;
    std::pair<int, std::vector<int>> find_cheapest_way_from_begin(int) const;
    int get_radius() const;
    int get_min_edges_count() const;
    int get_max_edges_count() const;
    
    friend class GraphBuilder;
};

#endif