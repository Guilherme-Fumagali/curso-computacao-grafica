#ifndef HITTABLE_SPHERE_H
#define HITTABLE_SPHERE_H

class HittableSphere {
    public:
    HittableSphere() = default;

    HittableSphere(const point3& center, double radius) {
            this->center = center;
            this->radius = radius;
        }

        virtual bool hit(const ray& r) {
            vec3 oc = r.origin() - center;
            auto a = dot(r.direction(), r.direction());
            auto b = 2.0 * dot(oc, r.direction());
            auto c = dot(oc, oc) - radius*radius;
            auto discriminant = b*b - 4*a*c;
            return (discriminant >= 0);
        }

    public:
        point3 center;
        double radius{};
};

#endif //HITTABLE_SPHERE_H
