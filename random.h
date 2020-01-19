
#ifndef RT_RANDOM_H
#define RT_RANDOM_H

#include <functional>
#include <random>

inline double random_double() {
    // Not my code in the slightest
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    static std::function<double()> rand_generator =
            std::bind(distribution, generator);
    return rand_generator();
}
#endif