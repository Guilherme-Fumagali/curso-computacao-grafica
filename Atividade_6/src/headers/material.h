#ifndef MATERIAL_H
#define MATERIAL_H

#include "src/utils/utils.h"

/**
 * @brief This class represents a generic material.
 *
 * This class is an abstract base class for different types of material, that can be applied to objects in the scene.
 */
class material {
public:
    virtual ~material() = default;

    /**
     * @brief Scatter function for the material.
     *
     * This function calculates the scattering of a ray when it hits an object made of this material.
     *
     * @param r_in The ray.
     * @param rec The @ref hit_record of the ray.
     * @param attenuation The attenuation of the ray after it hits the object.
     * @param scattered The scattered ray after it hits the object.
     * @return A boolean value indicating whether the ray was scattered or not.
     */
    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
    ) const = 0;
};

/**
 * @brief This class represents a lambertian material.
 *
 * A lambertian material scatters light in all directions equally.
 */
class lambertian : public material {
public:
    /**
     * @brief Constructor for the lambertian class.
     *
     * @param a The albedo of the material.
     */
    lambertian(const color& a) : albedo(a) {}

    /**
     * @brief Scatter function for the lambertian material.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        auto scatter_direction = rec.normal + random_vec3_unit_vector();

        // Catch degenerate scatter direction
        if (near_zero(scatter_direction))
            scatter_direction = rec.normal;

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

private:
    color albedo;
};


/**
 * @class metal
 * @brief This class represents a metallic material.
 *
 * A metallic material reflects light in a single direction.
 */
class metal : public material {
public:
    /**
     * @brief Constructor for the metal class.
     *
     * @param a The albedo of the material.
     * @param f The fuzziness of the material. If the value is greater than 1, it is clamped to 1.
     */
    metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    /**
     * @brief Scatter function for the metallic material.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected + fuzz*random_vec3_in_unit_sphere());
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

private:
    color albedo;
    double fuzz;
};


/**
 * @class dielectric
 * @brief This class represents a dielectric material.
 *
 * Clear dielectric materials like water, glass, and diamond exhibit reflection and refraction when struck by a light ray. The process involves randomly selecting between reflection and refraction, producing only one scattered ray per interaction.
 */
class dielectric : public material {
public:
    /**
     * @brief Constructor for the dielectric class.
     *
     * @param index_of_refraction The index of refraction of the material.
     */
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}

    /**
     * @brief Scatter function for the dielectric material.
     */
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0/ir) : ir;

        vec3 unit_direction = unit_vector(r_in.direction());
        double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        vec3 direction;

        if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
            direction = reflect(unit_direction, rec.normal);
        else
            direction = refract(unit_direction, rec.normal, refraction_ratio);

        scattered = ray(rec.p, direction);
        return true;
    }

private:
    double ir; // Index of Refraction

    /**
     * @brief Schlick's approximation for reflectance.
     *
     * @param cosine The cosine of the angle between the ray and the normal.
     * @param ref_idx The index of refraction of the material.
     * @return The reflectance.
     */
    static double reflectance(double cosine, double ref_idx) {
        // Use Schlick's approximation for reflectance.
        auto r0 = (1-ref_idx) / (1+ref_idx);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }
};
#endif