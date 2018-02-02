//
// Created by eddy on 2/1/2023.
//

#ifndef KLEINRAY_RAY_H
#define KLEINRAY_RAY_H
#include <limits>
#include <glm/glm.hpp>
class Ray {
public:
    static constexpr float kEpsilon = 0.0001f;
    static constexpr float kInfinity = std::numeric_limits<float>::max();
    Ray() {
        origin = glm::vec3(0.0f);
        direction = glm::vec3(0.0f);
    }

    Ray(glm::vec3 origin, glm::vec3 direction) {
        this->origin = origin;
        this->direction = direction;
    }

    Ray(glm::vec3 origin, glm::vec3 direction, float tMin, float tMax) {
        this->origin = origin;
        this->direction = direction;
        this->tMin = tMin;
        this->tMax = tMax;
    }

    glm::vec3 at(float t) const {
        return origin + t * direction;
    }

    glm::vec3 origin;
    glm::vec3 direction;
    float tMin = kEpsilon;
    float tMax = kInfinity;
};


#endif //KLEINRAY_RAY_H
