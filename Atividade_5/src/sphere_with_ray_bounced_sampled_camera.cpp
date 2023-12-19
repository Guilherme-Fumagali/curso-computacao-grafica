#include "src/utils/utils.h"

#include "src/headers/camera/ray_bounced_sampled_camera.h"
#include "src/headers/hittable/HittableList.h"
#include "src/headers/hittable/HittableSphere.h"

int main() {
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam(400, 16.0 / 9.0, 100, 50);

    cam.render(world, "sphere_with_ray_bounced_sampled_camera.png");
}