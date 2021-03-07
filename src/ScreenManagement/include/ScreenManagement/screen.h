#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <utility>
#include "iostream"

namespace screen_management {
class Screen {
    public:
        Screen(std::pair<int, int> size, const char name[]) {
            this->pixelBuffer = new GLubyte[size.first * size.second * 3];
            this->size = size;

            glutInitDisplayMode(GLUT_DOUBLE);
            glutInitWindowSize(size.first, size.second);
            glutInitWindowPosition(0,0);

	        this->windowId = glutCreateWindow(name);
        }

        void ClearScreen();
        void Display();
    protected:
    private:
        int windowId;
        GLubyte* pixelBuffer;
        std::pair<int, int> size;
};
}
