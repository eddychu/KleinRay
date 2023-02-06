//
// Created by eddy on 2/1/2023.
//

#include "Image.h"
#include <sstream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
Image::Image(int width, int height) {
    this->width = width;
    this->height = height;
    pixels.resize(width * height);
}

Image::~Image() {

}

void Image::setPixel(int x, int y, float r, float g, float b) {
    pixels[y * width + x] = glm::vec4(r, g, b, 1.0f);
}

void Image::setPixel(int x, int y, const glm::vec3 &color) {
    pixels[y * width + x] = glm::vec4(color, 1.0f);
}

void Image::save(const char *filename) {
    std::vector<unsigned char> data(width * height * 4);
    for (int i = 0; i < width * height; i++) {
        data[i * 4 + 0] = (unsigned char) (pixels[i].r * 255);
        data[i * 4 + 1] = (unsigned char) (pixels[i].g * 255);
        data[i * 4 + 2] = (unsigned char) (pixels[i].b * 255);
        data[i * 4 + 3] = (unsigned char) (pixels[i].a * 255);
    }
    stbi_write_png(filename, width, height, 4, data.data(), width * 4);
}