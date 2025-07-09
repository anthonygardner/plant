#pragma once

#include <cmath>
#include <random>

#include <plant/math/vector.hpp>

namespace plant::filters {

class KalmanFilter {
private:
    std::mt19937 gen{std::random_device{}()};
    std::normal_distribution<float> noise_dist{0.0, 0.1};

public:
    plant::math::Vector x, y;

    // Constructors
    KalmanFilter(plant::math::Vector x) : x(x) {}

plant::math::Vector predict() {
    plant::math::Vector w = { 
        noise_dist(gen),
        noise_dist(gen), 
        noise_dist(gen) 
    };

    return this->x + w;
}

};

}  // namespace plant::filters