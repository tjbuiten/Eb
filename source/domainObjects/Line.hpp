#pragma once
#include <GLUT/glut.h>
#include <Coordinate.hpp>

class Line {
	private:
                int screenWidth;
                Coordinate start, end;
	public:
                Line(int screenWidth, Coordinate start, Coordinate end): start(start), end(end) {
                this->screenWidth = screenWidth;
                }

                void draw(GLubyte* pixelBuffer);
};