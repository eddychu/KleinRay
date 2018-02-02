//
// Created by eddy on 2/1/2023.
//

#ifndef KLEINRAY_CAMERA_H
#define KLEINRAY_CAMERA_H

#include "Transform.h"
#include "Ray.h"
class Camera
{
public:
    Camera(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up, float fov)
        :  fov(fov) {
        auto to_local = glm::lookAt(eye, center, up);
        auto to_world = glm::inverse(to_local);
        transform.localToWorld = to_world;
        transform.worldToLocal = to_local;
    }


    Ray generateRay(const glm::vec2 &pixelCoord);

    Transform transform;
    float fov;
};

#endif // KLEINRAY_CAMERA_H
