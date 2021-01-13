#pragma once
#include "Glut.hpp"
#include "Vector2.hpp"
#include <iostream>

class Screen {
    private:
        Vector2<int> size;
        GLubyte* pixelBuffer;
        int windowId;
	public:
        Screen(std::string screenName, Vector2<int> size): size(size) {
            glutInitDisplayMode(GLUT_DOUBLE);
            glutInitWindowSize(*size.x, *size.y);
            glutInitWindowPosition(0,0);
	        this->windowId = glutCreateWindow(screenName.c_str());
            this->pixelBuffer = new GLubyte[(*size.x) * (*size.y) * 3];
        }

        void SetPixel(Vector2<int> coordinate);

        void ClearScreen();

        void UpdateScreen();

        void Display();
};