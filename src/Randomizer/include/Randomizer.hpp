#ifndef RANDOMIZE_HPP
#define RANDOMIZE_HPP

#include <utility>

struct Randomizer {
    Randomizer();
    int generate_on_range(int, int) const;
    std::pair<int, int> generate_point_in_circle(int) const;
};  

#endif