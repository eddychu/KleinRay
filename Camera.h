//
// Created by eddy on 2/1/2023.
//

#ifndef KLEINRAY_CAMERA_H
#define KLEINRAY_CAMERA_H

#include "Transform.h"
#include "Ray.h"
class Camera {
public:
    Camera(float vfov, glm::vec2 resolution,  float focalLength, float aperture);
    Ray generateRay(const glm::vec2& pixelCoord);
private:
    Transform transform;
    glm::vec2 size; // size of the image plane
    float focalLength; // focal length of the camera
    glm::vec2 resolution; // resolution of the image plane
    float aperture; // aperture of the camera
};


#endif //KLEINRAY_CAMERA_H
