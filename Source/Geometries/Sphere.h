//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_SPHERE_H
#define KLEINRAY_SPHERE_H
#include "Core/Hittable.h"
#include <glm/gtx/intersect.hpp>
class Sphere : public Hittable {
public:
    glm::vec3 center;
    float radius;
    Sphere(glm::vec3 center, float radius) : center(center), radius(radius) {}
    bool hit(const Ray &ray, HitRecord *record) const override {
        glm::vec3 position;
        glm::vec3 normal;
        if (glm::intersectRaySphere(ray.origin, ray.direction, center, radius, position, normal)) {
            float t = glm::distance(ray.origin, position);
            if (t > ray.tMin && t < ray.tMax) {
                record->t = t;
                record->point = position;

                record->normal = normal;
                return true;
            }

        }
        return false;
    }

    virtual glm::vec3 sample() const override {
        return glm::vec3(0);
    }

    virtual float pdf(const glm::vec3 &point) const override {
        return 0;
    }
};


#endif //KLEINRAY_SPHERE_H
