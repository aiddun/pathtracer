
#ifndef RT_PLANE_H
#define RT_PLANE_H

#include "object.h"

class plane : public object{
public:
    plane(){}
    plane(float x1, float z1, float x2, float z2, float y) : x1(x1), z1(z1), x2(x2), z2(z2), y(y) {}

    virtual hit_record hit(const ray &r, float t_min, float t_max) const;

    float x1;
    float z1;
    float x2;
    float z2;
    float y;

};

hit_record plane::hit(const ray &r, float t_min, float t_max) const {
    // Find hitting t
    // a_z+b_z * t = plane_z
    // t = (plane_z - a_z) / b_z

    float t = (y - r.origin.y()) / r.direction.y();
    vec3 hitSpot = r.point_at_parameter(t);

//    if (t_min < t && t < t_max) {
        // If in the range
        if ((hitSpot.x() >= x1) ^ (hitSpot.x() >= x2) &&
            (hitSpot.y() >= z1) ^ (hitSpot.y() >= z2)) {
            hit_record rec;

            // Store hit properties for pass back
            rec.hits = true;
            rec.t = t;
            rec.p = hitSpot;
            float direction = std::signbit(rec.p.y() - r.origin.y());
            rec.normal = vec3(1.0, direction, 1.0);

            return rec;
        }
//    }

    return {false};

}


#endif //RT_PLANE_H
