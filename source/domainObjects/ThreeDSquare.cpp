#include <ThreeDSquare.hpp>

void ThreeDSquare::draw(GLubyte* pixelBuffer) {
    int x = this->coordinate.x;
    int y = this->coordinate.y;
    int z  = this->coordinate.z;

    Square(
        this->screenWidth,
        Coordinate(
            x,
            y,
            z
        ),
        this->size
    ).draw(pixelBuffer);
    Square(
        this->screenWidth,
        Coordinate(
            x + this->depth * 3,
            y + this->depth * 3,
            z + this->depth
        ),
        this->size
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x, y , z),
        Coordinate(x + this->depth * 3, y + this->depth * 3, this->depth)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x, y + this->size, 0),
        Coordinate(x + this->depth * 3, y + this-> size + this->depth * 3, this->depth)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x + this->size, y , z),
        Coordinate(x + this->size + this->depth * 3, y + this->depth * 3, this->depth)
    ).draw(pixelBuffer);

    Line(
        this->screenWidth,
        Coordinate(x + this->size, y + this->size, 0),
        Coordinate(x + this->size + this->depth * 3, y + this-> size + this->depth * 3, this->depth)
    ).draw(pixelBuffer);
}