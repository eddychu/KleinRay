//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_PLANE_H
#define KLEINRAY_PLANE_H

#include "Core/Hittable.h"
class Plane : public Hittable {
public:
    Plane(glm::vec3 normal, float distance) : normal(normal), distance(distance) {

    }
    bool hit(const Ray &ray, HitRecord *record) const override {
        float t = (distance - glm::dot(normal, ray.origin)) / glm::dot(normal, ray.direction);
        if (t > ray.tMin && t < ray.tMax) {
            record->t = t;
            record->point = ray.at(t);
            // check if the normal is facing the ray
//            if (glm::dot(normal, ray.direction) > 0) {
//                normal = -normal;
//            }
            record->normal = normal;

            return true;
        }
        return false;
    }
    glm::vec3 normal;
    float distance;

    virtual glm::vec3 sample() const override {
        return glm::vec3(0);
    }

    virtual float pdf(const glm::vec3 &point) const override {
        return 0;
    }
};


#endif //KLEINRAY_PLANE_H
