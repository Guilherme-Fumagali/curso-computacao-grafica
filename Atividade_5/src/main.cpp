#include "src/utils/utils.h"

#include "src/headers/camera/view_direction_camera.h"
#include "src/headers/hittable/HittableTriangle.h"
#include "headers/hittable/HittableSphere.h"
#include "src/headers/hittable/HittableList.h"
#include "Triangle.h"
#include "Loader.h"

void loadObjectInWorld(hittable_list& world, const char* source, const vec3& position = vec3(0,0,0), const vec3& scale = vec3(1,1,1)) {
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

        triangle hittable_triangle(vertice_a, vertice_b, vertice_c, normal_a, normal_b, normal_c);

        world.add(make_shared<triangle>(hittable_triangle));
    }
}

int main(int argc, char **argv) {
    if (argc != 3 || (argv[1][0] != '0' && argv[1][0] != '1' && argv[1][0] != '2' && argv[1][0] != '3') || (argv[2][0] != 'l' && argv[2][0] != 'm' && argv[2][0] != 'h')) {
        std::cerr << "Usage: " << argv[0] << " <camera position (0 at 2)>" << " <quality ('l', 'm', 'h')>" << std::endl;
        return 1;
    }

    hittable_list world;
    world.add(make_shared<sphere>(point3(5,2,0), 1));
    world.add(make_shared<sphere>(point3(0,2,5), 1));
    world.add(make_shared<sphere>(point3(0,2,-5), 1));
    loadObjectInWorld(world, "src/static/objects/pyramid.obj", vec3(0,2,0), vec3(4,4,4));
    loadObjectInWorld(world, "src/static/objects/cube.obj",  vec3(0,-13,0), vec3(100,10,100));

    camera cam;
    cam.image_width = 1200;
    cam.aspect_ratio = 4.0 / 3.0;
    if (argv[2][0] == 'l') {
        cam.samples_per_pixel = 10;
        cam.max_depth = 5;
    } else if (argv[2][0] == 'm') {
        cam.samples_per_pixel = 40;
        cam.max_depth = 20;
    } else {
        cam.samples_per_pixel = 100;
        cam.max_depth = 50;
    }

    if (argv[1][0] == '0') {
        cam.vfov     = 75;
        cam.lookfrom = point3(8,3,-5); // perto/longe, baixo/cima, esquerda/direita
        cam.lookat   = point3(0,0,0);
    } else if (argv[1][0] == '1') {
        cam.vfov     = 7;
        cam.lookfrom = point3(70,80,-30); // atras/frente, baixo/cima, esquerda/direita
        cam.lookat   = point3(0,0,0);
    } else if (argv[1][0] == '2') {
        cam.vfov     = 2;
        cam.lookfrom = point3(400,0,0);
        cam.lookat   = point3(0,0,0);
    } else if (argv[1][0] == '3') {
        cam.vfov     = 30;
        cam.lookfrom = point3(400,0,0);
        cam.lookat   = point3(0,0,0);
    }

    cam.vup      = vec3(0,1,0);

    cam.render(world, "main_camera_position_" + std::string(argv[1]) + ".png");
}

