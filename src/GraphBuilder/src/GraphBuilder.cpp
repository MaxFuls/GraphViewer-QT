#include "GraphBuilder.hpp"

#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

Graph GraphBuilder::build_random_graph(int vertex_count, int radius, int edges_min, int edges_max) const {
    std::vector<std::pair<int, int>> vertexes(vertex_count);
    std::vector<std::vector<int>> edges(vertex_count);
    std::vector<std::vector<int>> distances(vertex_count);
    std::vector<std::vector<std::pair<int, int>>> adj_tab(vertex_count);
    for(int i = 0; i < vertex_count; ++i) {
        vertexes[i] = random.generate_point_in_circle(radius);
    }
    int xdif;
    int ydif;
    int distance;
    for(int i = 0; i < vertex_count; ++i) {
        for(int j = 0, sub_vertex, edges_count = random.generate_on_range(edges_min, edges_max);
                j < edges_count && edges[i].size() < edges_count; ++j) {
            sub_vertex = random.generate_on_range(0, vertex_count - 1);
            while(std::find(edges[i].begin(), edges[i].end(), sub_vertex) != edges[i].end() ||
                  edges[sub_vertex].size() == edges_max || sub_vertex == i) {

                    sub_vertex = random.generate_on_range(0, vertex_count - 1);
            }
            edges[i].push_back(sub_vertex);
            edges[sub_vertex].push_back(i);
            xdif = vertexes[i].first - vertexes[sub_vertex].first;
            ydif = vertexes[i].second - vertexes[sub_vertex].second;
            distance = std::sqrt(xdif*xdif + ydif*ydif);
            distances[i].push_back(distance);
            distances[sub_vertex].push_back(distance);
            adj_tab[i].push_back({sub_vertex, distance}); 
        }
    }
    return Graph(vertexes, edges, distances, adj_tab, radius, edges_min, edges_max);
}