//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_SAMPLING_H
#define KLEINRAY_SAMPLING_H
#include <glm/glm.hpp>
#include <glm/ext.hpp>
inline float randf(float min = 0.0f, float max = 1.0f)
{
    return glm::linearRand(min, max);
}

inline glm::vec3 sampleSphere(const glm::vec2 &rv)
{
    float phi = 2.0f * glm::pi<float>() * rv.x;
    float cosTheta = 2.0 * rv.y - 1.0;
    float sinTheta = glm::sqrt(1.0f - cosTheta * cosTheta);
    float x = sinTheta * glm::cos(phi);
    float y = sinTheta * glm::sin(phi);
    float z = cosTheta;
    return glm::normalize(glm::vec3(x, y, z));
}

inline float sampleSpherePDF()
{
    return 1.0f / (4.0f * glm::pi<float>());
}

inline glm::vec3 sampleHemisphere(const glm::vec2 &rv)
{
    float phi = 2.0f * glm::pi<float>() * rv.x;
    float cosTheta = rv.y;
    float sinTheta = glm::sqrt(1.0f - cosTheta * cosTheta);
    float x = sinTheta * glm::cos(phi);
    float y = sinTheta * glm::sin(phi);
    float z = cosTheta;
    return glm::normalize(glm::vec3(x, y, z));
}

inline float sampleHemispherePDF()
{
    return 0.5f / glm::pi<float>();
}

inline glm::vec3 sampleHemisphereCosine(const glm::vec2 &rv)
{
    float phi = 2.0f * glm::pi<float>() * rv.x;
    float cosTheta = glm::sqrt(rv.y);
    float sinTheta = glm::sqrt(1.0f - cosTheta * cosTheta);
    float x = sinTheta * glm::cos(phi);
    float y = sinTheta * glm::sin(phi);
    float z = cosTheta;
    return glm::normalize(glm::vec3(x, y, z));
}

inline float sampleHemisphereCosinePDF(const glm::vec3 &wi)
{
    return glm::max(0.0f, glm::dot(wi, glm::vec3(0.0f, 0.0f, 1.0f))) / glm::pi<float>();
}

#endif // KLEINRAY_SAMPLING_H
