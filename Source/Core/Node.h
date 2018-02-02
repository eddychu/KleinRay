//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_NODE_H
#define KLEINRAY_NODE_H

#include <Core/Material.h>
#include <Core/Hittable.h>
#include <Core/Transform.h>
class Node : public Hittable {
public:
    Hittable* hittable;
    Material* material;
    Node(Hittable* hittable, Material* material) : hittable(hittable), material(material) {

    }

    bool hit(const Ray &ray, HitRecord *record) const override {
        if (hittable->hit(ray, record)) {
            record->material = material;
            return true;
        }
        return false;
    }
};


#endif //KLEINRAY_NODE_H
