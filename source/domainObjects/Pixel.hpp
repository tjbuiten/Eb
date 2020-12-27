#pragma once
#include <GLUT/glut.h>
#include <Coordinate.hpp>

class Pixel {
	private:
        Coordinate coordinate;
        int size;
        int screenWidth;
	public:
        Pixel (int screenWidth, Coordinate coordinate, int size): coordinate(coordinate) {
            this->screenWidth = screenWidth;
            this->size = size;
        }
        
        void draw(GLubyte* pixelBuffer);
};