//
// Created by gfumagali on 18/12/23.
//

#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <random>
#include <limits>
#include <memory>


// Using

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

// Common Headers
#include "src/headers/Interval.h"
#include "src/headers/ray.h"
#include "vec3.h"
#include "vec2.h"

inline vec3 random_vec3() {
    return {random_double(), random_double(), random_double()};
}

inline vec3 random_vec3(double min, double max) {
    return {random_double(min,max), random_double(min,max), random_double(min,max)};
}

inline vec3 random_vec3_in_unit_sphere() {
    while (true) {
        auto p = random_vec3(-1,1);
        if (p.length_squared() < 1)
            return p;
    }
}

inline vec3 random_in_unit_disk() {
    while (true) {
        auto p = vec3(random_double(-1,1), random_double(-1,1), 0);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

inline vec3 random_vec3_unit_vector() {
    return unit_vector(random_vec3_in_unit_sphere());
}

inline vec3  random_vec3_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_vec3_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

#endif //UTILS_H
