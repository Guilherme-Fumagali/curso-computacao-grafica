#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "Hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

/**
 * @brief This class represents a list of @ref hittable objects.
 * */
class hittable_list : public hittable {
public:
    std::vector<shared_ptr<hittable>> objects;

    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    /**
     * Clears the list
     * */
    void clear() { objects.clear(); }

    /**
     * Adds a new object to the list
     * @param object Object to add
     */
    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    /**
     * Checks if a ray hits any of the objects in the list
     * @param r Ray to check
     * @param ray_t Interval of the ray to check
     * @param rec Hit record
     * @return True if the ray hits any of the objects, false otherwise
     */
    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        for (const auto& object : objects) {
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }
};

#endif