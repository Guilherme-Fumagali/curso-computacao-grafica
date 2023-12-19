#include "src/utils/utils.h"

#include "src/headers/camera/sampled_camera.h"
#include "src/headers/hittable/HittableList.h"
#include "src/headers/hittable/HittableSphere.h"

int main() {
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam(1000, 21.0 / 9.0, 100);

    cam.render(world, "sphere_with_sampled_camera.png");
}