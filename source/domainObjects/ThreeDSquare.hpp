#pragma once
#include <GLUT/glut.h>
#include <Coordinate.hpp>
#include <Line.hpp>
#include <Square.hpp>

class ThreeDSquare {
	private:
        Coordinate coordinate;
        int size;
        int screenWidth;
        int depth;
	public:
        ThreeDSquare (int screenWidth, Coordinate coordinate, int size, int depth): coordinate(coordinate) {
            this->screenWidth = screenWidth;
            this->size = size;
            this->depth = depth;
        }
        
        void draw(GLubyte* pixelBuffer);
};