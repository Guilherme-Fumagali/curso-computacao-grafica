#ifndef HITTABLE_H
#define HITTABLE_H

#include "src/headers/ray.h"
#include "headers/Interval.h"

/**
 * @brief This class represents a record of a hit. It contains the point of intersection,
 * the normal at the intersection point, and the parameter t from the ray equation.
 */
class hit_record {
public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.

        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

/**
 * @brief This class represents a hittable object.
 * */
class hittable {
    public:
        virtual ~hittable() = default;

        /**
         * Checks if a ray hits the object
         * @param r Ray to check
         * @param ray_t Interval of the ray to check
         * @param rec Hit record
         * @return True if the ray hits the object, false otherwise
         */
        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};


#endif //HITTABLE_H
