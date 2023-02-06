//
// Created by eddy on 2/2/2023.
//

#include <Core/Renderer.h>
#include <Core/Image.h>
#include <Core/Integrator.h>
#include <Core/Sampling.h>
void Renderer::render(Scene &scene, Camera &camera, Integrator* integrator, const char *filename)
{
    Image image(width, height);
    float aspect = (float)image.width / (float)image.height;
    for (int y = 0; y < image.height; y++)
    {
        for (int x = 0; x < image.width; x++)
        {
            glm::vec3 color(0.0);
            for (int s = 0; s < samples; s++)
            {
                float xn = (2.0f * (x + randf()) / (float)image.width - 1.0f) * aspect;
                float yn = (1.0f - 2.0f * (y + randf()) / (float)image.height);
                auto ray = camera.generateRay(glm::vec2(xn, yn));
                color += integrator->li(scene, ray, maxDepth);
            }
            color /= (float)samples;
            color = glm::clamp(color, glm::vec3(0.0), glm::vec3(1.0));
            image.setPixel(x, y, color);
        }
    }
    image.save(filename);
}

