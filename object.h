#ifndef RT_OBJECT_H
#define RT_OBJECT_H


#include "ray.h"
#include "material.h"

//
struct hit_record {
    bool hits;
    // Ray "length" parameter
    float t;
    // hit point
    vec3 p;
    // normal vector from hit point
    vec3 normal;

    material *mat;

};

class object {
public:
    // Abstract class
    virtual hit_record hit(const ray& r, float t_min, float t_max) const = 0;
};


#endif //RT_OBJECT_H
