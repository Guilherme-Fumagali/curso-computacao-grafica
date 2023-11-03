#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "Loader.h"

#include <iostream>

bool hit_triangle(const point3& A, const point3& B, const point3& C, const ray& r) {

    vec3 AB = B - A;
    vec3 AC = C - A;
    vec3 N = cross(AB, AC); // Normal vector of the triangle

    double area = N.length(); // Area of the triangle

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

color ray_color(const ray& r, vector<vec3> vertices, vector<Triangle> triangles) {
    for (int i = 0; i < triangles.size(); i++) {
        Triangle triangle = triangles[i];

        vec3 A = vertices[(unsigned int)triangle[0].x()];
        vec3 B = vertices[(unsigned int)triangle[1].x()];
        vec3 C = vertices[(unsigned int)triangle[2].x()];

        if (hit_triangle(A, B, C, r))
            return color(1, 0, 0);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main(int argc, char **argv) {
    /*if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }*/

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

    vector<vec3> vertices;
    vector<vec2> uvs; // texture coordinates
    vector<vec3> normals;
    vector<Triangle> triangles;

    //const char *file = argv[1];

    bool res = Loader::loadObj("/home/gfumagali/Documents/PG/Atividade_4/piston_cup_trophy.obj", &vertices, &uvs, &normals, &triangles);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << argv[1] << std::endl;
        return 1;
    }

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, vertices, triangles);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}