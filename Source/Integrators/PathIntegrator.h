//
// Created by eddy on 2/3/2023.
//

#ifndef KLEINRAY_PATHINTEGRATOR_H
#define KLEINRAY_PATHINTEGRATOR_H

#include <Core/Integrator.h>
class PathIntegrator : public Integrator
{
public:
    PathIntegrator() {}
    virtual glm::vec3 li(const Scene &scene, const Ray &ray, int depth) const override
    {
//        if (depth <= 0)
//        {
//            return glm::vec3(0.0);
//        }
//        HitRecord record;
//        if (!scene.hit(ray, &record)) {
//            return glm::vec3(0);
//        }
//        glm::vec3 emitted = glm::vec3(0);
//        for(auto light: scene.lights) {
//            emitted += light->le(ray, record);
//        }
//        return emitted;
//        auto sample = record.material->sample(-ray.direction, record);
//        Ray scatterRay(record.point, sample.wi);
//        float cosTheta = glm::dot(record.normal, sample.wi);
//        if(cosTheta <= 0) {
//            return emitted;
//        }
//        return emitted +
//            li(scene, scatterRay, depth - 1) * cosTheta / sample.pdf / glm::pi<float>();
    }
};

#endif // KLEINRAY_PATHINTEGRATOR_H
