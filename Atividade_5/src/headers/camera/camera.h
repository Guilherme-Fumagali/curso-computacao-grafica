#ifndef CAMERA_H
#define CAMERA_H

#include "src/utils/utils.h"

#include "src/headers/color.h"
#include "src/headers/hittable/Hittable.h"
#include "MatrixIOImage.hpp"

#include <iostream>

/**
 * @brief Defines a camera with a given image width and aspect ratio
 * */
class camera {
public:
    /*Constructor with image width and aspect ratio*/
    camera(int image_width, double aspect_ratio) {
        this->image_width = image_width;
        this->aspect_ratio = aspect_ratio;
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
                auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
                auto ray_direction = pixel_center - center;
                ray r(center, ray_direction);

                color pixel_color = ray_color(r, world);
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
     * @brief Calculates the color of a ray
     * This function calculates the color of a ray by checking if it hits an object in the scene. If it does, it
     * returns the color of the object. If it doesn't, it returns the background color.
     *
     * @param r Ray to calculate the color of
     * @param world List of hittable objects @ref hittable_list
     * @return Color of the ray
     * */
    color ray_color(const ray& r, const hittable& world) const {
        hit_record rec;

        if (world.hit(r, interval(0, infinity), rec)) {
            return 0.5 * (rec.normal + color(1,1,1));
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }
};

#endif