//
// Created by eddy on 2/1/2023.
//

#include "Camera.h"


Camera::Camera(float vfov, glm::vec2 resolution,  float focalLength, float aperture) {
    this->focalLength = focalLength;
    this->resolution = resolution;
    this->aperture = aperture;
    float theta = glm::radians(vfov);
    float halfHeight = glm::tan(theta / 2.0f);
    float halfWidth = halfHeight * size.x / size.y;
    this->size = glm::vec2(halfWidth * 2.0f, halfHeight * 2.0f);
}

Ray Camera::generateRay(const glm::vec2& pixelCoord) {
    auto ix = -size.x / 2.0f + (pixelCoord.x + 0.5f) * size.x / resolution.x;
    auto iy = size.y / 2 - (pixelCoord.y + 0.5f) * size.y / resolution.y;
    glm::vec3 origin = transform.transformPoint(glm::vec3(0.0f));
    glm::vec3 direction = transform.transformVector(glm::vec3(ix, iy, -focalLength));
    return Ray(origin, direction);
}