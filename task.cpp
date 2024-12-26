#include <algorithm>
#include <vector>

// Рекурсивная функция для поиска пути фиксированной длины из вершины from в вершину to
// По реализации вроде ничего сложного: нам передают вершину в которой мы находися сейчас, ту, в коорую нужно прийти,
// построенный к данному моменту путь, длину, а также вектор посещенных вершин. Если длина равна нулю, то есть мы пришли
// в последнюю допустимую по длине вершину, проверяем является ли она той в которую нам нужно было прийти изначально,
// если да, то добавляем ее в путь и путь добавляем в вектор всех путей, иначе выходим. Если длина не равна нулю,
// проверяем, что текущая вершина не является той, в которую нужно придти, если не является, добавляем ее в путь и
// рекурсивно вызываем функцию для всех соседей текущей вершины, которых еще не посетили.
void find_path(std::vector<std::vector<int>>& paths, int from, int to, std::vector<int> path, int lengh,
               std::vector<bool> is_visited, const std::vector<std::vector<int>>& edges) {
    if (lengh == 0) {
        if (from == to) {
            path.push_back(from);
            paths.push_back(std::move(path));
        }
    } else {
        if (from == to) {
            return;
        } else {
            path.push_back(from);
            for (auto v : edges[from]) {
                if (!is_visited[v]) {
                    is_visited[v] = true;
                    find_path(paths, v, to, path, lengh - 1, is_visited, edges);
                }
            }
        }
    }
}

// Функция которая запускает рекурсивный поиск путей ограниченной длины
std::vector<std::vector<int>> find_path_with_lengh(int from, int to, int lengh,
                                                   const std::vector<std::vector<int>>& edges) {
    std::vector<std::vector<int>> paths;
    std::vector<bool> is_visited(edges.size(), false);
    is_visited[from] = true;
    for (auto v : edges[from]) {
        find_path(paths, v, to, {from}, lengh - 1, is_visited, edges);
    }
    return paths;
}

// Главная функция алгоритма, которя пытается по минимальному пути построить оптимальный путь стоимости, заданной
// интервалом [min, max]. Если минимальная стоимость укладывается в интервал, возвращаем минимальный
// путь, если стоимость минимального путь больше max, то оптимального пути не сущетсвует, возвращаем пустой вектор,
// иначе начинаем поиск оптимального пути. Суть алгоритма состоит в том, чтобы уточнить стоимость, вклинивая между
// двумя соседними вершинами дополнительные вершины. Подробнее в комментариях в теле функции.
std::vector<int> find_optimal_path(std::vector<int>& min_path, const std::vector<std::vector<int>>& edges,
                                   const std::vector<std::vector<int>>& distances, int min_price, int min, int max) {
    if (min_price >= min && min_price <= max) {
        return min_path;
    } else if (min_price > max) {
        return {};
    }
    int incomplete_lengh;
    bool is_modifed = false;
    // В этом цикле ищем пути между соседними вершинами различной длины, сначала пробуем найти путь длины два, если
    // нашли, то is_modified присваем занчение true и модифицируем наш исходный путь: добавляем вершину между двумя
    // соседями, если стоимость модифицированного пути попала в допустимый интервал, завершаем поиск, иначе продолжаем
    // искать. Если перебрали все пары вершин смотрим is_modifed, если он равен true, значит мы уточняли путь и стоит
    // еще раз пройтись по всем соседним вершинам и поискать между ними путь длины два, если is_modified = false,
    // инкрементируем lengh и вновь проходимся по соседним вершинам.
    for (int lengh = 2, max_lengh = edges.size(); lengh < max_lengh;) {
        for (int first = 0, second = 1, size = min_path.size(); second < size; ++first, ++second) {
            incomplete_lengh = min_price - distances[first][second];
            auto paths = find_path_with_lengh(min_path[first], min_path[second], lengh, edges);
            std::vector<std::pair<int, int>> lenghs(paths.size());
            for (int i = 0, size = paths.size(); i < size; ++i) {
                lenghs[i].second = i;
                for (int f = 0, s = 1; s < lengh; ++f, ++s) {
                    lenghs[i].first += distances[paths[i][f]][paths[i][s]];
                }
                lenghs[i].first += incomplete_lengh;
            }
            std::sort(lenghs.begin(), lenghs.end(),
                      [](auto first, auto second) { return first.first > second.second; });
            if (lenghs.front().first < min) {
                auto it = std::next(min_path.begin(), second);
                min_path.insert(it, std::next(paths[lenghs.back().second].begin(), 1),
                                std::next(paths[lenghs.back().second].end(), -1));
            } else if (lenghs.back().first > max) {
                continue;
            } else {
                for (const auto& v : lenghs) {
                    if (v.first >= min && v.first <= max) {
                        std::vector<int> result;
                        result.insert(result.end(), min_path.begin(), std::next(min_path.begin(), first));
                        result.insert(result.end(), paths[v.second].begin(), paths[v.second].end());
                        result.insert(result.end(), std::next(min_path.begin(), second), min_path.end());
                        return result;
                    }
                }
            }
        }
        if (is_modifed) {
            is_modifed = false;
            lengh = 2;
        } else {
            ++lengh;
        }
    }
    return {};
}