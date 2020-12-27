#include "Line.hpp"
#include "Pixel.hpp"
#include <cmath>

void Line::draw(GLubyte* pixelBuffer) {
    float stepsizeX = 0;
    float stepsizeY = 0;

    int steps = 0;

    if (abs(start.x - end.x) >= abs(start.y - end.y)) {
        stepsizeX = (start.x > end.x) ? -1 : 1;
        steps  = abs(start.x - end.x) / abs(stepsizeX);

        stepsizeY = (end.y - start.y) / steps;

    } else {
        stepsizeY = (start.y > end.y) ? -1 : 1;
        steps  = abs(start.y - end.y) / abs(stepsizeY);

        stepsizeX = (end.x - start.x) / steps;
    }

    float stepsizeZ = (float) (end.z - start.z) / steps;

    for (int step = 0; step <= steps; step++) {
        Pixel(
            this->screenWidth,
            Coordinate(
                start.x + (stepsizeX * step),
                start.y + (stepsizeY * step),
                start.z + (stepsizeZ * step)
            ),
            5
        ).draw(pixelBuffer);
    }
}