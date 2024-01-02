#ifndef CAMERA_SAMPLE_H
#define CAMERA_SAMPLE_H

#include "src/utils/utils.h"

#include "src/headers/color.h"
#include "src/headers/hittable/Hittable.h"
#include "MatrixIOImage.hpp"


#include <iostream>

/**
 * @brief This camera render a diffuse object with a given image width and aspect ratio.
 * Also, it avoids the aliasing effect by sampling multiple rays per pixel.
 * */
class camera {
public:
    camera(int image_width, double aspect_ratio, int samples_per_pixel, int max_depth) {
        this->image_width = image_width;
        this->aspect_ratio = aspect_ratio;
        this->samples_per_pixel = samples_per_pixel;
        this->max_depth = max_depth;
    }

    /**
     * @brief Renders the scene
     * This function renders the scene by calculating the color of each pixel and saving it to a matrix, which is then
     * saved to a file.
     *
     * @param world List of hittable objects @ref hittable_list
     * @param filename Name of the file to save the image to
     * */
    void render(const hittable& world, const std::string& filename) {
        initialize();

        int **matrix = new int *[image_height];
        for (int i = 0; i < image_height; i++)
            matrix[i] = new int[image_width * 3];

        for (int j = 0; j < image_height; ++j) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                color pixel_color(0,0,0);
                for (int sample = 0; sample < samples_per_pixel; ++sample) {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                }

                pixel_color = write_color_gamma(pixel_color, samples_per_pixel);
                matrix[j][i * 3] = (int) (pixel_color.x() * 255);
                matrix[j][i * 3 + 1] = (int) (pixel_color.y() * 255);
                matrix[j][i * 3 + 2] = (int) (pixel_color.z() * 255);
            }
        }

        MatrixIOImage::generateImageFromMatrix(matrix, image_width, image_height, filename);

        for (int i = 0; i < image_height; i++)
            delete[] matrix[i];
        delete[] matrix;
        std::clog << "\rDone.                 \n";
    }

private:
    double aspect_ratio;   // Ratio of image width over height
    int    image_width;    // Rendered image width in pixel count
    int    samples_per_pixel; // Number of samples per pixel
    int    max_depth;      // Maximum number of ray bounces
    int    image_height;   // Rendered image height
    point3 center;         // Camera center
    point3 pixel00_loc;    // Location of pixel 0, 0
    vec3   pixel_delta_u;  // Offset to pixel to the right
    vec3   pixel_delta_v;  // Offset to pixel below

    /**
     * @brief Initializes the camera
     * This function initializes the camera by calculating the image height, the viewport dimensions, the viewport
     * vectors, and the pixel delta vectors.
     * */
    void initialize() {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        center = point3(0, 0, 0);

        // Determine viewport dimensions.
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left =
                center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    /**
     * @brief Returns a ray from the camera to the pixel at location i,j
     * This function returns a ray from the camera to the pixel at location i,j. The ray is randomly sampled within the
     * pixel.
     *
     * @param i Pixel row
     * @param j Pixel column
     * @return Ray from the camera to the pixel at location i,j
     * */
    ray get_ray(int i, int j) const {
        // Get a randomly sampled camera ray for the pixel at location i,j.

        auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
        auto pixel_sample = pixel_center + pixel_sample_square();

        auto ray_origin = center;
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction);
    }

    /**
    * @brief Returns a random point in the square surrounding a pixel at the origin.
    *
    * This function generates a random point within the square surrounding a pixel at the origin.
    * The random point is calculated by generating a random double for both x and y coordinates,
    * then scaling and shifting them by the pixel delta vectors.
    *
    * @return A vec3 representing the random point in the square surrounding a pixel at the origin.
    */
    vec3 pixel_sample_square() const {
        // Returns a random point in the square surrounding a pixel at the origin.
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

    /**
    * @brief Calculates the color of a ray
    * This function calculates the color of a ray by checking if it hits an object in the scene. If it does, it
    * returns the color of the object. If it doesn't, it returns the background color.
    *
    * @param r Ray to calculate the color of
    * @param world List of hittable objects @ref hittable_list
    * @return Color of the ray
    * */
    color ray_color(const ray& r, int depth, const hittable& world) const {
        hit_record rec;

        // If we've exceeded the ray bounce limit, no more light is gathered.
        if (depth <= 0)
            return color(0,0,0);

        if (world.hit(r, interval(0.001, infinity), rec)) {
            vec3 direction = rec.normal + random_vec3_unit_vector();
            return 0.25 * ray_color(ray(rec.p, direction), depth-1, world);
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }
};

#endif //CAMERA_SAMPLE_H