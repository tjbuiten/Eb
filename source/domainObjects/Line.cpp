#include "Line.hpp"
#include "Pixel.hpp"
#include <iostream>

void Line::draw(GLubyte* pixelBuffer) {
    Pixel startPixel = Pixel(this->screenWidth, this->start, 5);
    Pixel endPixel = Pixel(this->screenWidth, this->end, 5);

    startPixel.draw(pixelBuffer);
    endPixel.draw(pixelBuffer);
}