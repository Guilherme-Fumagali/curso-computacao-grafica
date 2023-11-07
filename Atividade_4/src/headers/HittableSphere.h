#ifndef HITTABLE_SPHERE_H
#define HITTABLE_SPHERE_H

#include "Hittable.h"

/**
 * @brief Class for hittable spheres
 * */
class HittableSphere : public Hittable {
    public:
        HittableSphere() = default;

        HittableSphere(const point3& center, double radius) {
                this->center = center;
                this->radius = radius;
            }

        /**
         * Checks if a ray hits the sphere
         * @param r Ray to check
         * @return True if the ray hits the sphere, false otherwise
         */
        bool hit(const ray& r) override {
            vec3 oc = r.origin() - center; // vector from center to origin

            /* Calculating coefficients for quadratic equation */
            auto a = dot(r.direction(), r.direction());
            auto b = 2.0 * dot(oc, r.direction());
            auto c = dot(oc, oc) - radius*radius;

            /* If discriminant is greater than or equal to 0, the ray hits the sphere */
            auto discriminant = b*b - 4*a*c;
            return (discriminant >= 0);
        }

    private:
        point3 center;
        double radius{};
};

#endif //HITTABLE_SPHERE_H
