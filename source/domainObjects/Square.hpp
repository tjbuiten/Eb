#pragma once
#include <GLUT/glut.h>
#include <Coordinate.hpp>
#include <Line.hpp>

class Square {
	private:
        Coordinate coordinate;
        int size;
        int screenWidth;
	public:
        Square (int screenWidth, Coordinate coordinate, int size): coordinate(coordinate) {
            this->screenWidth = screenWidth;
            this->size = size;
        }
        
        void draw(GLubyte* pixelBuffer);
};