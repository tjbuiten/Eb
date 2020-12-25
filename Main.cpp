#include <iostream>
#include <OpenGL/gl3.h>

int main(int, char**) {
    glGetInteger64v(GL_MAJOR_VERSION, NULL);
    std::cout << "Hello, world!\n";

    return 0;
}