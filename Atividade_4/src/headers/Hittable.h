#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

/**
 * @brief Abstract class for hittable objects
 * This class is used to represent hittable objects in the scene.
 * */
class Hittable {
    public:
        Hittable() = default;

        /**
         * Checks if a ray hits the object
         * @param r Ray to check
         * @return True if the ray hits the object, false otherwise
         * */
        virtual bool hit(const ray& r) = 0;
};

#endif //HITTABLE_H
