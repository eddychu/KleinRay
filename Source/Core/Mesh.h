//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_MESH_H
#define KLEINRAY_MESH_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>
#include "Core/Ray.h"
#include "Core/Hittable.h"
#include <glm/gtx/intersect.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
struct Mesh : public Hittable
{
    Mesh()
    {
    }



    bool hit(const Ray &ray, HitRecord *record) const override
    {
        bool hit = false;
        float closest = ray.tMax;

        for (int i = 0; i < indices.size(); i += 3)
        {
            glm::vec3 point;
            if (glm::intersectLineTriangle(ray.origin, ray.direction, vertices[indices[i]], vertices[indices[i + 1]], vertices[indices[i + 2]], point)) {
                float t = glm::distance(ray.origin, point);
                if (t < closest && t > ray.tMin)
                {
                    closest = t;
                    record->point = point;
                    record->t = t;

                    record->normal = glm::normalize(glm::cross(vertices[indices[i + 1]] - vertices[indices[i]], vertices[indices[i + 2]] - vertices[indices[i]]));
                    hit = true;
                }
            }
        }
        return hit;
    }

    virtual glm::vec3 sample() const override {
        return glm::vec3(0);
    }

    virtual float pdf(const glm::vec3 &point) const override {
        return 0;
    }

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> tangents;
    std::vector<glm::vec3> bitangents;
    std::vector<glm::vec3> colors;
    std::vector<unsigned int> indices;
};

#endif // KLEINRAY_MESH_H
