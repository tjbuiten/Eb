#include "ScreenManagement/screen.h"

namespace screen_management {
void Screen::ClearScreen() {
    glutSetWindow(this->windowId);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    this->pixelBuffer = new GLubyte[size.first * size.second * 3];
}

void Screen::Display() {
    glutSetWindow(this->windowId);
    glDrawPixels(this->size.first, this->size.second, GL_RGB, GL_UNSIGNED_BYTE, this->pixelBuffer);
	glutSwapBuffers();
}
}