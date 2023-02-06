//
// Created by eddy on 2/2/2023.
//

#ifndef KLEINRAY_RENDERER_H
#define KLEINRAY_RENDERER_H

#include <Core/Scene.h>
#include <Core/Camera.h>
#include <Core/Integrator.h>
class Renderer
{
public:
    Renderer(int width, int height, int samples, int maxDepth) : width(width), height(height), samples(samples), maxDepth(maxDepth) {}

    void render(Scene &scene, Camera &camera, Integrator *integrator, const char *filename);
    int width;
    int height;
    int samples;
    int maxDepth;
};

#endif // KLEINRAY_RENDERER_H
