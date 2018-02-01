#include <iostream>
#include "Image.h"
#include "Camera.h"
int main() {

    Camera camera(90.0f, glm::vec2(200, 100), 1.0f, 0.0f);
    Image image(200, 100);
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            auto ray = camera.generateRay(glm::vec2(x + 0.5f, y + 0.5f));
            auto color = glm::normalize(ray.direction) * 0.5f + 0.5f;
            image.setPixel(x, y, color.r, color.g, color.b);
        }
    }
    image.save("test.png");
    return 0;
}
