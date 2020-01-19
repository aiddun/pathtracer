#include "vec3.h"
#include "ray.h"
#include "object.h"
#include "sphere.h"
#include "hittable_list.h"
#include "random.h"
#include "Camera.h"
#include "plane.h"

#include <iostream>
#include <cmath>

#define EYECOORD Vec3(0, 0, -1)
#define LENGTH (unsigned short) 200
#define WIDTH (unsigned short) 400
#define SAMPLES (unsigned short) 1000


vec3 colorSky(const ray& r){
    vec3 unit_direction = unit_vectorize(r.direction);
    float t = 0.5f*(unit_direction.y() + 1.0f);
    // Blue and white blending
//    return unit_vector();
    return (1.0f - t) * unit_vector() + t * vec3(0.5f, 0.7f, 1.0f);

}
vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0 * vec3(random_double(), random_double(), random_double()) - vec3(1, 1, 1);
    } while (p.squared_length() >= 1.0);
    return p;
}


vec3 color(const ray& r, object *world) {

    hit_record rec = world->hit(r, 0.001, MAXFLOAT);

    if (rec.hits) {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color(ray(rec.p, target - rec.p), world);
    } else {
        return colorSky(r);
    }

}



int main() {
    std::cout << "P3\n" << WIDTH << " " << LENGTH << "\n255\n";

    const vec3 lower_left_corner(-2.0, -1.0, -1.0);
    const vec3 horizontal(4.0, 0.0, 0.0);
    const vec3 vertical(0.0, 2.0, 0.0);
    const vec3 origin(0.0, 0.0, 0.0);

    int listSize = 2;
    object *list[listSize];
    list[0] = new sphere(vec3(-.5, 0, -1), .5);
//     list[1] = new plane(-2, 0, 2, -2, 0);
    list[1] = new sphere(vec3(0,-100.5,-1), 100);
//    list[2] = new sphere(vec3(.5,0,-1), .5);


    object *world = new hittable_list(list, listSize);

    Camera cam;

    // LENGTH - 1 to 0
    for (short j = short(LENGTH - 1); j >= 0; --j) {
        // 0 to WIDTH - 1
        for (unsigned short i = 0; i < WIDTH; ++i) {

            vec3 col(0, 0, 0);
            for (int s = 0; s < SAMPLES; s++) {
                float u = float(i + random_double()) / float(WIDTH);
                float v = float(j + random_double()) / float(LENGTH);
                ray r = cam.get_ray(u, v);
                col += color(r, world);
            }
            col /= float(SAMPLES);

            col.square_root();

            int ir = int(255.99*col.r());
            int ig = int(255.99*col.g());
            int ib = int(255.99*col.b());
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}
