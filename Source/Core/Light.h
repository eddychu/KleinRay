//
// Created by eddy on 2/3/2023.
//

#ifndef KLEINRAY_LIGHT_H
#define KLEINRAY_LIGHT_H

#include <glm/glm.hpp>
#include "Ray.h"
#include "Hittable.h"
class Light {
public:
    virtual ~Light() = default;
    virtual glm::vec3 sample_li(const HitRecord& record, glm::vec3 *point, float* pdf) const = 0;
};

class PointLight : public Light {
public:
    PointLight(glm::vec3 position, glm::vec3 intensity) : position(position), intensity(intensity) {}

    virtual glm::vec3 sample_li(const HitRecord& record, glm::vec3 *point, float* pdf) const override {
        *point = position;
        auto l = position - record.point;
        *pdf = 1;
        auto distanceSquared = glm::dot(l, l);
        return intensity / distanceSquared;
    }

    glm::vec3 position;
    glm::vec3 intensity;
};


#endif //KLEINRAY_LIGHT_H
