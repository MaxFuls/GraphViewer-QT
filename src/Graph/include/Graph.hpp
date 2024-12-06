#include <vector>
#include <utility>

class Graph {
private:
    std::vector<std::pair<int, int>> vertexes;
    std::vector<std::vector<int>> edges;
public:
    Graph();
    Graph(const std::vector<std::pair<int, int>>&, const std::vector<std::vector<int>>&);
    const std::vector<std::pair<int, int>>& get_vertexes() const;
    const std::vector<std::vector<int>>& get_edges() const;
};