#pragma once

#include <utility>

struct Randomizer {
    Randomizer();
    int generate_on_range(int, int) const;
    std::pair<int, int> generate_point_in_circle(int) const;
};