//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_SCENE_H
#define KLEINRAY_SCENE_H

#include "Core/Node.h"
#include "Core/Light.h"
#include <vector>
struct Scene {
    bool hit(const Ray& ray, HitRecord *hitRecord) const {
        bool hit = false;
        float closest = ray.tMax;
        HitRecord record;
        for (auto node: nodes) {
            if (node->hit(ray, &record)) {
                if (record.t < closest && record.t > ray.tMin) {
                    *hitRecord = record;
                    closest = record.t;
                    hit = true;
                }
            }
        }
        return hit;
    }
    std::vector<Node*> nodes;
    std::vector<Light*> lights;

};


#endif //KLEINRAY_SCENE_H
