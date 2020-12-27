#include "Pixel.hpp"
#include <iostream>

void Pixel::draw(GLubyte* pixelBuffer) {
    for (int x = this->coordinate.x; x < this->coordinate.x + this->size; x++) {
        for (int y = this->coordinate.y; y < this->coordinate.y + this->size; y++) {
            int position = (x + y * this->screenWidth) * 3;
            pixelBuffer[position] = 255;
            pixelBuffer[position + 1] = 255;
            pixelBuffer[position + 2] = 255;
        }
    }
}