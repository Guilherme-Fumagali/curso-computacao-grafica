#include "src/utils/utils.h"

#include "src/headers/camera/view_direction_camera.h"
#include "src/headers/hittable/HittableList.h"
#include "src/headers/hittable/HittableSphere.h"

int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),  -0.4));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5));

    camera cam(400, 16.0 / 9.0, 100, 50);

    cam.vfov     = 90;
    cam.lookfrom = point3(-2,2,1);
    cam.lookat   = point3(0,0,-1);
    cam.vup      = vec3(0,1,0);

    cam.render(world, "sphere_with_view_direction_camera.png");
}