//
// Created by eddy on 2/1/2023.
//

#ifndef KLEINRAY_TRANSFORM_H
#define KLEINRAY_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
class Transform {
public:
    Transform() {
        localToWorld = glm::mat4(1.0f);
        worldToLocal = glm::mat4(1.0f);
    }

    Transform(glm::mat4 localToWorld) {
        this->localToWorld = localToWorld;
        this->worldToLocal = glm::inverse(localToWorld);
    }

    glm::vec3 transformPoint(glm::vec3 point) {
        return glm::vec3(localToWorld * glm::vec4(point, 1.0f));
    }

    glm::vec3 transformVector(glm::vec3 vector) {
        return glm::vec3(localToWorld * glm::vec4(vector, 0.0f));
    }

    glm::vec3 transformNormal(glm::vec3 normal) {
        return glm::normalize(glm::vec3(glm::transpose(worldToLocal) * glm::vec4(normal, 0.0f)));
    }



    glm::mat4 localToWorld;
    glm::mat4 worldToLocal;
};


#endif //KLEINRAY_TRANSFORM_H
