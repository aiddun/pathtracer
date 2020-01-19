
#ifndef RT_HITTABLE_LIST_H
#define RT_HITTABLE_LIST_H


#include "ray.h"
#include "object.h"

class hittable_list : public object{
public:
    hittable_list(){}
    hittable_list(object** l, int size): size(size), list(l) {}

    virtual hit_record hit(const ray& r, float t_min, float t_max) const;

    object** list;
    int size;

};


#endif //RT_HITTABLE_LIST_H
