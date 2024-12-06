#include "Randomizer.hpp"

#include <ctime>
#include <random>
#include <cmath>

Randomizer::Randomizer() {
    std::srand(std::time(NULL));
}

int Randomizer::generate_on_range(int min, int max) const{
    int dif = max - min;
    return (std::rand() % dif) + min;
}

std::pair<int, int> Randomizer::generate_point_in_circle(int radius) const {
    int R = generate_on_range(0, radius);
    double alpha = ((generate_on_range(-180, 180))/180.0)*M_PI;
    return {R * std::cos(alpha), R * std::sin(alpha)};
} 