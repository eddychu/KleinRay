//
// Created by eddy on 2/1/2023.
//

#include "Transform.h"
Transform Transform::buildFromLookAt(const glm::vec3 &eye, const glm::vec3 &center, const glm::vec3 &up)
{
    Transform t;
    t.worldToLocal = lookAt(eye, center, up);
    t.localToWorld = glm::inverse(t.worldToLocal);
    return t;
}