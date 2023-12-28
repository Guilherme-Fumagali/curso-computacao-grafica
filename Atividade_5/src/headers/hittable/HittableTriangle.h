#ifndef HITTABLE_TRIANGLE_H
#define HITTABLE_TRIANGLE_H

#include "vec3.h"
#include "Hittable.h"

/**
 * @brief Class for hittable triangles
 * */
class triangle : public hittable {
public:
    triangle(point3 _vertice_a, point3 _vertice_b, point3 _vertice_c, vec3 _normal_a, vec3 _normal_b, vec3 _normal_c) {
        a = _vertice_a;
        b = _vertice_b;
        c = _vertice_c;
        normal_a = _normal_a;
        normal_b = _normal_b;
        normal_c = _normal_c;
    }

    /**
     * Checks if a ray hits the triangle
     * @param r Ray to check
     * @param ray_t Interval of the ray to check
     * @param rec Hit record
     * @return True if the ray hits the sphere, false otherwise
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 ab = b - a;
        vec3 ac = c - a;
        vec3 normal = cross(ab, ac); // Normal vector of the triangle

        double d = -dot(normal, a);
        double t = -(dot(normal, r.origin()) + d) / dot(normal, r.direction()); // Distance from the ray origin to the triangle plane
        if (t < ray_t.min || t > ray_t.max) return false; // The ray does not hit the triangle

        point3 p = r.at(t); // Intersection point

        vec3 ap = p - a;
        vec3 vp_ab = cross(ab, ap);
        if (dot(normal, vp_ab) < 0) return false;  // P is on the right side of AB

        vec3 bc = c - b;
        vec3 bp = p - b;
        vec3 vp_bc = cross(bc, bp);
        if (dot(normal, vp_bc) < 0) return false; // P is on the right side of BC

        vec3 ca = a - c;
        vec3 cp = p - c;
        vec3 vp_ca = cross(ca, cp);
        if (dot(normal, vp_ca) < 0) return false; // P is on the right side of CA

        // calculate barycentric coordinates
        double w1 = dot(cross(ab, ac), cross(ab, ap)) / dot(cross(ab, ac), cross(ab, ac));
        double w2 = dot(cross(ab, ac), cross(ac, ap)) / dot(cross(ab, ac), cross(ab, ac));
        double w3 = 1 - w1 - w2;
        vec3 outward_normal = w1 * normal_a + w2 * normal_b + w3 * normal_c;
        outward_normal = unit_vector(outward_normal);

        rec.t = t;
        rec.p = p;
        rec.set_face_normal(r, outward_normal);

        return true; // P is inside the triangle
    }

private:
    point3 a, b, c;
    vec3 normal_a, normal_b, normal_c;
};

#endif