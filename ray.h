#ifndef RT_RAY_H
#define RT_RAY_H

#include "vec3.h"

class ray {
    vec3 A;
    vec3 B;

    public:
        ray() {};
        ray(const vec3& a, const vec3& b): A(a), B(b){};
        vec3 &origin = A;
        vec3 &direction  = B;

        vec3 point_at_parameter(float t) const { return A + t * B; }
};

#endif