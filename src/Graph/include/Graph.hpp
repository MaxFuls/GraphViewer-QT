#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <utility>

class Graph {
private:
    std::vector<std::pair<int, int>> vertexes;
    std::vector<std::vector<int>> edges;
    int radius;
protected:
    Graph(const std::vector<std::pair<int, int>>&, const std::vector<std::vector<int>>&, int);
public:
    Graph();
    const std::vector<std::pair<int, int>>& get_vertexes() const;
    const std::vector<std::vector<int>>& get_edges() const;
    int get_radius() const;
    void recalculate_radius();
    friend class GraphBuilder;
};

#endif