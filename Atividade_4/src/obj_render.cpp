#include "color.h"
#include "src/headers/ray.h"
#include "MatrixIOImage.hpp"
#include "Loader.h"
#include "src/headers/HittableTriangle.h"

#include <iostream>

/**
 * @brief Calculates the color of a ray
 * This function calculates the color of a ray by checking if it hits any of the triangles in the scene.
 * If it hits a triangle, the color red is returned, otherwise the color of the sky is returned.
 *
 * @param r Ray to calculate the color of
 * @param vertices Vertices at viewport
 * @param triangles Indexes of vertices that form triangles
 * */
color ray_color(const ray& r, vector<vec3> vertices, const vector<Triangle>& triangles) {
    for (auto triangle : triangles) {
        vec3 A = vertices[(unsigned int)triangle[0].x()];
        vec3 B = vertices[(unsigned int)triangle[1].x()];
        vec3 C = vertices[(unsigned int)triangle[2].x()];

        if (HittableTriangle(A, B, C).hit(r))
            return {1, 0, 0};
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input obj file>" << " <output image file>" << std::endl;
        return 1;
    }

    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    /*------------ Camera ------------*/
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    auto camera_center = point3(0, 0, 1);

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

    /*------------ Loading obj file ------------*/
    vector<vec3> vertices;
    vector<vec2> uvs; // texture coordinates
    vector<vec3> normals;
    vector<Triangle> triangles;

    const char *file = argv[1];

    bool res = Loader::loadObj(file, &vertices, &uvs, &normals, &triangles);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << argv[1] << std::endl;
        return 1;
    }

    /*------------ Rendering ------------*/
    int **matrix = new int *[image_height];
    for (int i = 0; i < image_height; i++)
        matrix[i] = new int[image_width * 3];

    // Render
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, vertices, triangles);
            matrix[j][i * 3] = (int) (pixel_color.x() * 255);
            matrix[j][i * 3 + 1] = (int) (pixel_color.y() * 255);
            matrix[j][i * 3 + 2] = (int) (pixel_color.z() * 255);
        }
    }

    MatrixIOImage::generateImageFromMatrix(matrix, image_width, image_height, argv[2]);

    for (int i = 0; i < image_height; i++)
        delete[] matrix[i];
    delete[] matrix;

    std::clog << "\rDone.                 \n";
}