//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_RENDERER_H
#define KLEINRAY_RENDERER_H

#include "Scene.h"
#include "Camera.h"
class Renderer {
public:
    Renderer(int width, int height, int samples, int maxDepth) : width(width), height(height), samples(samples), maxDepth(maxDepth) {}

    void render(Scene& scene, Camera& camera, const char* filename);
    int width;
    int height;
    int samples;
    int maxDepth;
};


#endif //KLEINRAY_RENDERER_H
