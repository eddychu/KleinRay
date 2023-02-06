//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_HITTABLE_H
#define KLEINRAY_HITTABLE_H
#include <glm/glm.hpp>
#include "Ray.h"
class Material;
struct HitRecord {
    glm::vec3 point;
    glm::vec3 normal;
    float t = std::numeric_limits<float>::max();
    Material* material;
};
struct Hittable {
    virtual bool hit(const Ray &ray, HitRecord *record) const = 0;
    virtual glm::vec3 sample() const {
        return glm::vec3(0);
    }
    virtual float pdf(const glm::vec3 &point) const  {
        return 0;
    }
};


#endif //KLEINRAY_HITTABLE_H
