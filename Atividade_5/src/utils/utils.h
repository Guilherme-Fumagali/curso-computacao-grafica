//
// Created by gfumagali on 18/12/23.
//

#ifndef UTILS_H
#define UTILS_H

#include <cmath>
#include <limits>
#include <memory>


// Usings

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

// Common Headers
#include "src/headers/Interval.h"
#include "src/headers/ray.h"
#include "vec3.h"

#endif //UTILS_H
