//
// Created by eddy on 2/2/2023.
//

#include "Core/Renderer.h"
#include "Core/Image.h"
void Renderer::render(Scene& scene, Camera& camera, const char* filename) {
    Image image(width, height);
    float aspect = (float)image.width / (float)image.height;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            float xn = (2.0f * (x + 0.5f) / (float)image.width - 1.0f) * aspect;
            float yn = (1.0f - 2.0f * (y + 0.5f) / (float)image.height);
            auto ray = camera.generateRay(glm::vec2(xn, yn));
            HitRecord hitRecord;
            if (scene.hit(ray, &hitRecord)) {
                Ray shadowRay(hitRecord.point, scene.lights[0]->getDirection(hitRecord.point));
                HitRecord shadowHitRecord;
                shadowRay.tMax = glm::length(scene.lights[0]->getDistance(hitRecord.point));
                if (scene.hit(shadowRay, &shadowHitRecord)) {
                    image.setPixel(x, y, 0, 0, 0);
                    continue;
                }

                auto cosTheta = glm::dot(shadowRay.direction, hitRecord.normal);
                if (cosTheta < 0) {
                    image.setPixel(x, y, 0, 0, 0);
                    continue;
                }
                // printf("hit\n");
                auto lightIntensity = scene.lights[0]->getIntensity(hitRecord.point);
                auto albedo = hitRecord.material->albedo * cosTheta * lightIntensity;
                albedo = glm::min(albedo, glm::vec3(1.0f));
                image.setPixel(x, y, albedo.x, albedo.y, albedo.z);
            } else {
                image.setPixel(x, y, 0, 0, 0);
            }
        }
    }
    image.save(filename);
}