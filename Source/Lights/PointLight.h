//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_POINTLIGHT_H
#define KLEINRAY_POINTLIGHT_H

#include "Core/Light.h"
class PointLight : public Light {
public:
    PointLight(glm::vec3 position, glm::vec3 intensity) {
        this->position = position;
        this->intensity = intensity;
    }

    glm::vec3 getDirection(const glm::vec3& point) {
        return glm::normalize(position - point);
    }

    glm::vec3 getIntensity(const glm::vec3& point) {
        auto distance = glm::length(position - point);
        auto attenuation = 1.0f / (distance * distance);
        return attenuation * intensity;
    }

    float getDistance(const glm::vec3& point) {
        return glm::length(position - point);
    }

    glm::vec3 position;
    glm::vec3 intensity;
};


#endif //KLEINRAY_POINTLIGHT_H
