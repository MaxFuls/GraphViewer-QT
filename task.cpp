#include <vector>

std::vector<std::vector<int>> find_path_with_lengh(int from, int to, int lengh,
                                                   const std::vector<std::vector<int>>& edges) {}

std::vector<int> find_path(const std::vector<int>& min_path, const std::vector<std::vector<int>>& edges,
                           const std::vector<std::vector<int>>& distances, int min_price, int reference, int min,
                           int max) {
    if (min_price >= min && min_price <= max) {
        return min_path;
    }
    int incomplete_lengh;
    for (int lengh = 2, max_lengh = edges.size(); lengh < max_lengh; ++lengh)
        for (int first = 0, second = 1, size = min_path.size(); second < size; ++first, ++second) {
            incomplete_lengh = min_price - distances[first][second];
            auto paths = find_path_with_lengh(min_path[first], min_path[second], lengh, edges);
            std::vector<int> lenghs(paths.size());
            for (int i = 0, size = paths.size(); i < size; ++i) {
                for (int f = 0, s = 1; s < lengh; ++f, ++s) {
                    lenghs[i] += distances[paths[i][f]][paths[i][s]];
                }
                lenghs[i] += incomplete_lengh;
            }
                }
}