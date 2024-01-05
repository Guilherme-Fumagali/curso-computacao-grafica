#include "src/utils/utils.h"

#include "src/headers/camera/view_direction_camera.h"
#include "src/headers/hittable/HittableTriangle.h"
#include "headers/hittable/HittableSphere.h"
#include "src/headers/hittable/HittableList.h"
#include "Triangle.h"
#include "Loader.h"

void loadObjectInWorld(hittable_list& world, const char* source, const vec3& position = vec3(0,0,0), const vec3& scale = vec3(1,1,1), shared_ptr<material> material = nullptr) {
    /*------------ Loading obj file ------------*/
    vector<vec3> vertices;
    vector<vec2> uvs; // texture coordinates
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool res = Loader::loadObj(source, &vertices, &uvs, &normals, &triangles);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << source << std::endl;
        return;
    }

    for (auto & t : triangles) {
        point3 vertice_a = (vertices[(unsigned int)t[0].x()] * scale) + position;
        point3 vertice_b = (vertices[(unsigned int)t[1].x()] * scale) + position;
        point3 vertice_c = (vertices[(unsigned int)t[2].x()] * scale) + position;

        point3 normal_a = normals[(unsigned int)t[0].z()];
        point3 normal_b = normals[(unsigned int)t[1].z()];
        point3 normal_c = normals[(unsigned int)t[2].z()];

        triangle hittable_triangle(vertice_a, vertice_b, vertice_c, normal_a, normal_b, normal_c, material);

        world.add(make_shared<triangle>(hittable_triangle));
    }
}

int main(int argc, char **argv) {
    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            auto choose_mat = random_double();
            auto choose_object = random_double();

            point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                shared_ptr<material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    auto albedo = random_vec3() * random_vec3();
                    sphere_material = make_shared<lambertian>(albedo);

                    if (choose_object < 0.33) {
                        world.add(make_shared<sphere>(center, 0.2, sphere_material));
                    } else if (choose_object < 0.66) {
                        loadObjectInWorld(world, "src/static/objects/pyramid.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    } else {
                        loadObjectInWorld(world, "src/static/objects/cube.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    }
                } else if (choose_mat < 0.95) {
                    // metal
                    auto albedo = random_vec3(0.5, 1);
                    auto fuzz = random_double(0, 0.5);
                    sphere_material = make_shared<metal>(albedo, fuzz);

                    if (choose_object < 0.33) {
                        world.add(make_shared<sphere>(center, 0.2, sphere_material));
                    } else if (choose_object < 0.66) {
                        loadObjectInWorld(world, "src/static/objects/pyramid.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    } else {
                        loadObjectInWorld(world, "src/static/objects/cube.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    }
                } else {
                    // glass
                    sphere_material = make_shared<dielectric>(1.5);

                    if (choose_object < 0.33) {
                        world.add(make_shared<sphere>(center, 0.2, sphere_material));
                    } else if (choose_object < 0.66) {
                        loadObjectInWorld(world, "src/static/objects/pyramid.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    } else {
                        loadObjectInWorld(world, "src/static/objects/cube.obj", center, vec3(0.2,0.2,0.2), sphere_material);
                    }
                }
            }
        }
    }

    auto material1 = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    auto material2 = make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    auto material3 = make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    camera cam;

    cam.aspect_ratio      = 16.0 / 9.0;
    cam.image_width       = 1200;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 50;

    cam.vfov     = 20;
    cam.lookfrom = point3(13,2,3);
    cam.lookat   = point3(0,0,0);
    cam.vup      = vec3(0,1,0);

    cam.render(world, "main.png");
}

