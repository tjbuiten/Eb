#include <Screen.hpp>
#include <iostream>

void Screen::SetPixel(Vector2<int> coordinate) {
    int position = (*coordinate.x + *coordinate.y * *this->size.x) * 3;
    this->pixelBuffer[position] = 255;
    this->pixelBuffer[position + 1] = 255;
    this->pixelBuffer[position + 2] = 255;
}

void Screen::ClearScreen() {
    glutSetWindow(this->windowId);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Screen::UpdateScreen() {
    this->pixelBuffer = new GLubyte[(*size.x) * (*size.y) * 3];
}

void Screen::Display() {
    glutSetWindow(this->windowId);
    glDrawPixels(*this->size.x, *this->size.y, GL_RGB, GL_UNSIGNED_BYTE, this->pixelBuffer);
	glutSwapBuffers();
}