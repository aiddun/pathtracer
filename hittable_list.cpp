
#include "hittable_list.h"

hit_record hittable_list::hit(const ray &r, float t_min, float t_max) const {
    double closest_t = t_max;
    hit_record record = {false};

    for (int i = 0; i < size; ++i) {
        hit_record temp_record = list[i]->hit(r, t_min, t_max);
        if (temp_record.hits){
            if (temp_record.t < closest_t){
                closest_t = temp_record.t;
                record = temp_record;
            }
        }
    }

    return record;
}
