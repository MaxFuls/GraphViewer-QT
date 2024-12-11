#include "Graph.hpp"

#include <vector>
#include <algorithm>
#include <limits>

Graph::Graph(const std::vector<std::pair<int, int>>& vertexes,
             const std::vector<std::vector<int>>& edges, 
             const std::vector<std::vector<int>>& distances,
             const std::vector<std::vector<std::pair<int, int>>>& adj_table,
             int radius, int min_edges_count, int max_edges_count)
     : vertexes(vertexes), edges(edges), distances(distances), adj_table(adj_table), radius(radius),
       min_edges_count(min_edges_count), max_edges_count(max_edges_count) {
        compute_path_and_dists();
}

const std::vector<std::vector<int>>& Graph::get_edges() const {
    return edges;
}

const std::vector<std::pair<int, int>>& Graph::get_vertexes() const {
    return vertexes;
}

const std::vector<std::vector<int>>& Graph::get_distances() const {
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

void Graph::compute_path_and_dists() {
    const int INF = std::numeric_limits<int>::max(); 
    int n = vertexes.size();
    dists = std::vector<int>(n, INF);
    paths = std::vector <int>(n, -1);
    std::vector <bool> used(n);
    dists[0] = 0;
    int min_dist = 0;
    int min_vertex = 0;
    while (min_dist < INF) {
        int i = min_vertex;
        used[i] = true;
        for (auto edge: adj_table[i]) {
            int j = edge.first;
            int wt = edge.second;
            if (dists[i] + wt < dists[j]) {
                dists[j] = dists[i] + wt;
                paths[j] = i;
            }
        }
        min_dist = INF;
        for (int j = 0; j < n; ++j)
            if (!used[j] && dists[j] < min_dist) {
                min_dist = dists[j];
                min_vertex = j;
        }
    }
}

std::pair<int, std::vector<int>> Graph::find_cheapest_way_from_begin(int end) const {
    std::vector<int> path;
    int price = dists[end];
    while (end != -1)
    {
        path.push_back(end);
        end = paths[end];
    }
    std::reverse(path.begin(), path.end());
    return std::make_pair(price, path);
}