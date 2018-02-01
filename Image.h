//
// Created by eddy on 2/1/2023.
//

#ifndef KLEINRAY_IMAGE_H
#define KLEINRAY_IMAGE_H
#include <glm/glm.hpp>
#include <vector>
class Image {
public:
    Image(int width, int height);
    ~Image();

    void setPixel(int x, int y, float r, float g, float b);
    void save(const char* filename);

    int width;
    int height;
    std::vector<glm::vec4> pixels;
};


#endif //KLEINRAY_IMAGE_H
