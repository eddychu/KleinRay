//
// Created by eddy on 2/6/2023.
//

#ifndef KLEINRAY_WHITTED_H
#define KLEINRAY_WHITTED_H

#include <Core/Integrator.h>
class WhittedIntegrator : public Integrator {
public:
    glm::vec3 li(const Scene &scene, const Ray &ray, int depth) const override {
        if (depth <= 0)
        {
            return glm::vec3(0.0);
        }
        HitRecord record;
        if (!scene.hit(ray, &record)) {
            return glm::vec3(0);
        }
        glm::vec3 color = glm::vec3(0);
        for(auto light: scene.lights) {
            glm::vec3 lightPoint;
            float shadowRayPDF;
            auto emitted = light->sample_li(record, &lightPoint, &shadowRayPDF);
            auto shadowRayDir = lightPoint - record.point;
            Ray shadowRay(record.point, glm::normalize(shadowRayDir));
            shadowRay.tMax = glm::length(shadowRayDir);
            HitRecord shadowRecord;
            if(!scene.hit(shadowRay, &shadowRecord)) {
                color += emitted * glm::dot(record.normal, shadowRayDir) / shadowRayPDF;
            }
        }
        auto sample = record.material->sample(-ray.direction, record);
        Ray scatterRay(record.point, sample.wi);
        float cosTheta = glm::dot(record.normal, sample.wi);
        if(cosTheta <= 0) {
            return color * sample.attenuation;
        }
        return (color +
            li(scene, scatterRay, depth - 1) * sample.attenuation * cosTheta / sample.pdf / glm::pi<float>()) * sample.attenuation;
    }
};


#endif //KLEINRAY_WHITTED_H
