//
// Created by eddy on 2/3/2023.
//

#ifndef KLEINRAY_INTEGRATOR_H
#define KLEINRAY_INTEGRATOR_H
#include <glm/glm.hpp>
#include <Core/Scene.h>
class Integrator
{
public:
    virtual ~Integrator() = default;
    virtual glm::vec3 li(const Scene &scene, const Ray &ray, int maxDepth) const = 0;
};

#endif // KLEINRAY_INTEGRATOR_H
