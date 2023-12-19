
#include "color.h"
#include "src/headers/hittable/Hittable.h"
#include "src/headers/hittable/HittableList.h"
#include "src/headers/hittable/HittableSphere.h"
#include "utils/utils.h"
#include "MatrixIOImage.hpp"

#include <iostream>

/**
 * @brief Calculates the color of a ray
 * This function calculates the color of a ray by checking if it hits any of the objects in the scene.
 *
 * @param r Ray to calculate the color of
 * @param world List of hittable objects @ref hittable_list
 * @return Color of the ray considering the normal of the object it hits
 * */
color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

/**
 * @brief Main function to render a scene with a sphere and a plane
 * */
int main() {

    // Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Creating scene
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera

    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    auto viewport_upper_left = camera_center
                               - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    /*------------ Rendering ------------*/
    int **matrix = new int *[image_height];
    for (int i = 0; i < image_height; i++)
        matrix[i] = new int[image_width * 3];
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, world);
            matrix[j][i * 3] = (int) (pixel_color.x() * 255);
            matrix[j][i * 3 + 1] = (int) (pixel_color.y() * 255);
            matrix[j][i * 3 + 2] = (int) (pixel_color.z() * 255);
        }
    }

    MatrixIOImage::generateImageFromMatrix(matrix, image_width, image_height, "sphere_with_normals.png");

    for (int i = 0; i < image_height; i++)
        delete[] matrix[i];
    delete[] matrix;
    std::clog << "\rDone.                 \n";
}