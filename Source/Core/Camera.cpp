//
// Created by eddy on 2/1/2023.
//

#include "Camera.h"

Ray Camera::generateRay(const glm::vec2 &pixelCoord)
{
    float scale = tan(fov / 2);
    float x = pixelCoord.x * scale;
    float y = pixelCoord.y * scale;
    glm::vec3 direction = glm::normalize(transform.localToWorld * glm::vec4(x, y, -1, 0));
    glm::vec3 origin = transform.localToWorld * glm::vec4(0, 0, 0, 1);

    return Ray(origin, direction);
}