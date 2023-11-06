#ifndef HITTABLE_TRIANGLE_H
#define HITTABLE_TRIANGLE_H

#include "vec3.h"
#include "ray.h"

class HittableTriangle {
    public:
        HittableTriangle() = default;

        HittableTriangle(const point3& A, const point3& B, const point3& C) {
                this->A = A;
                this->B = B;
                this->C = C;
        }

        bool hit(const ray& r) {
            vec3 AB = B - A;
            vec3 AC = C - A;
            vec3 N = cross(AB, AC); // Normal vector of the triangle

            vec3 AO = A - r.origin(); // Vector from the ray origin to the triangle origin

            double t = dot(AO, N) / dot(r.direction(), N); // Distance from the ray origin to the triangle plane
            if (t < 0) return false; // The triangle is behind the ray origin, do not intersect

            point3 P = r.at(t); // Intersection point

            vec3 AP = P - A;
            vec3 vpAB = cross(AB, AP);
            if (dot(N, vpAB) < 0) return false;  // P is on the right side of AB

            vec3 BC = C - B;
            vec3 BP = P - B;
            vec3 vpBC = cross(BC, BP);
            if (dot(N, vpBC) < 0) return false; // P is on the right side of BC

            vec3 CA = A - C;
            vec3 CP = P - C;
            vec3 vpCA = cross(CA, CP);
            if (dot(N, vpCA) < 0) return false; // P is on the right side of CA

            return true; // P is inside the triangle
        }

    public:
        point3 A;
        point3 B;
        point3 C;
};

#endif //HITTABLE_TRIANGLE_H
