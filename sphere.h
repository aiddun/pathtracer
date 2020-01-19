
#ifndef RT_SPHERE_H
#define RT_SPHERE_H

#include "object.h"

class sphere : public object{
public:
    sphere(){};
    sphere(vec3 cen, float r) : center(cen), radius(r)  {};

    virtual hit_record hit(const ray& r, float t_min, float t_max) const;

    vec3 center;
    float radius;
};

hit_record sphere::hit(const ray &r, float t_min, float t_max) const {
    float a = dot(r.direction, r.direction);
    vec3 origin_minus_c = r.origin - center;
    float b = 2.0f * dot(origin_minus_c, r.direction);
    float c = dot(origin_minus_c, origin_minus_c) - radius * radius;

    float discriminant = b*b - 4*a*c;

    if (discriminant < 0){
        return {false};
    }

    // Quadratic formula, where sqrt(discriminant) is sqrt("b^2 - 4ac")
    // Finds closest hit spot to eye (hence "-" "+-" term)
    float t = (-b - sqrtf(discriminant)) / (2 * a);
    if (t_min < t && t < t_max){
        hit_record rec;

        // Store hit properties for pass back
        rec.hits = true;
        rec.t = t;
        rec.p = r.point_at_parameter(rec.t);
        rec.normal = (rec.p - center) / radius;

        return rec;
    } else {
        // If other root works
        t = (-b + sqrtf(discriminant)) / (2 * a);
        if (t_min < t && t < t_max) {
            hit_record rec;

            rec.hits = true;
            rec.t = t;
            rec.p = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center) / radius;
            return rec;
        }
    }

    return {false};
}


#endif //RT_SPHERE_H
