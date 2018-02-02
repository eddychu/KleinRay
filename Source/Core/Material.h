//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_MATERIAL_H
#define KLEINRAY_MATERIAL_H
#include "Core/Ray.h"
#include "Core/Hittable.h"
class Material {
public:
    glm::vec3 albedo;
    float index;
    float roughness;
    float metallic;
    float emittance;
    Material(glm::vec3 albedo = glm::vec3(1.0, 1.0, 1.0), float index = 1.0f, float roughness = 0.0f, float metallic = 0.0f, float emittance = 0.0f) : albedo(albedo), index(index), roughness(roughness), metallic(metallic), emittance(emittance) {

    }

    glm::vec3 bsdf(const Ray &ray, const HitRecord &record, const Ray &outgoingRay) const {
        return albedo;
    }

    glm::vec3 sample(const Ray &ray, const HitRecord &record, Ray *outgoingRay) const {
        return albedo;
    }
};


#endif //KLEINRAY_MATERIAL_H
