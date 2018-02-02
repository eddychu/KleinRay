//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_LIGHT_H
#define KLEINRAY_LIGHT_H

#include <glm/glm.hpp>
class Light {
public:
    virtual glm::vec3 getDirection(const glm::vec3& point) = 0;
    virtual glm::vec3 getIntensity(const glm::vec3& point) = 0;
    virtual float getDistance(const glm::vec3& point) = 0;
};


#endif //KLEINRAY_LIGHT_H
