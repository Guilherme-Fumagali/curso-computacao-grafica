#include "src/utils/utils.h"

#include "src/headers/camera/view_direction_camera.h"
#include "src/headers/hittable/HittableList.h"
#include "src/headers/hittable/HittableTriangle.h"
#include "Triangle.h"
#include "Loader.h"

int main() {
    /*------------ Loading obj file ------------*/
    vector<vec3> vertices;
    vector<vec2> uvs; // texture coordinates
    vector<vec3> normals;
    vector<Triangle> triangles;

    bool res = Loader::loadObj("/home/gfumagali/Documents/PG/Atividade_5/src/static/objects/cube.obj", &vertices, &uvs, &normals, &triangles);
    if (!res) {
        std::cerr << "Error: Could not load obj file " << "/home/gfumagali/Documents/PG/Atividade_5/src/static/objects/cube.obj" << std::endl;
        return 1;
    }

    hittable_list world;

    for (auto & t : triangles) {
        point3 vertice_a = vertices[(unsigned int)t[0].x()];
        point3 vertice_b = vertices[(unsigned int)t[1].x()];
        point3 vertice_c = vertices[(unsigned int)t[2].x()];

        point3 normal_a = normals[(unsigned int)t[0].z()];
        point3 normal_b = normals[(unsigned int)t[1].z()];
        point3 normal_c = normals[(unsigned int)t[2].z()];

        triangle hittable_triangle(vertice_a, vertice_b, vertice_c, normal_a, normal_b, normal_c);

        world.add(make_shared<triangle>(hittable_triangle));
    }

    camera cam(1000, 16.0 / 9.0, 1, 10);

    cam.vfov     = 30;
    cam.lookfrom = point3(4,3,-5);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.render(world, "main.png");
}