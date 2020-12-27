#include "Square.hpp"

void Square::draw(GLubyte* pixelBuffer) {
    int x = this->coordinate.x;
    int y = this->coordinate.y;
    int z = this->coordinate.z;

    Line(
        this->screenWidth,
        Coordinate(x, y, z),
        Coordinate(x, y + this->size, z)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x + this->size, y, z),
        Coordinate(x + this->size, y + this->size, z)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x, y, z),
        Coordinate(x + this->size, y, z)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x, y + this->size, z),
        Coordinate(x + this->size, y + this->size, z)
    ).draw(pixelBuffer);
}