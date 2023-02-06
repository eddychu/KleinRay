//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_MATERIAL_H
#define KLEINRAY_MATERIAL_H
#include "Core/Ray.h"
#include "Core/Hittable.h"
#include <Core/Sampling.h>
struct SampleRecord {
    glm::vec3 wi;
    glm::vec3 wo;
    float pdf;
    glm::vec3 attenuation;
};

class Material {
public:


    virtual SampleRecord sample(const glm::vec3 &wo, const HitRecord& hitRecord) const {
        SampleRecord record;
        return record;
    }

    virtual float pdf(const glm::vec3 &wi, const glm::vec3 &wo, const HitRecord &hitRecord) const {
        return 1;
    }
};

class Lambertian : public Material
{
public:
    Lambertian(glm::vec3 albedo) : albedo(albedo) {}

    SampleRecord sample(const glm::vec3 &wo, const HitRecord &hitRecord) const override
    {
        SampleRecord record;
        glm::vec2 rv(randf(), randf());
        record.wi = glm::normalize(sampleHemisphere(rv));
        record.wo = wo;
        record.pdf = pdf(record.wi, record.wo, hitRecord);
        record.attenuation = albedo;
        return record;
    }

    float pdf(const glm::vec3 &wi, const glm::vec3 &wo, const HitRecord &hitRecord) const override
    {
        // uniform sampling for now
        return 1.0f / (2.0f * glm::pi<float>());
    }

    glm::vec3 albedo;
};
#endif // KLEINRAY_MATERIAL_H
