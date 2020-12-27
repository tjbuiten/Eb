#include "Line.hpp"
#include "Pixel.hpp"
#include <iostream>
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

    std::cout << "startX: " << start.x << " endX: " << end.x << " startY: " << start.y << " endY: " << end.y << "\n";
    std::cout << "stepsizeX: " << stepsizeX << " stepsizeY: " << stepsizeY << " steps: " << steps << "\n";

    for (int step = 0; step <= steps; step++) {
        // std::cout << "x: " << start.x + (stepsizeX * step) << " y: " << start.y + (stepsizeY * step) << "\n";

        Pixel(
            this->screenWidth,
            Coordinate(
                start.x + (stepsizeX * step),
                start.y + (stepsizeY * step),
                0
            ),
            5
        ).draw(pixelBuffer);
    }
}