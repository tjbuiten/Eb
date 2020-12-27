#include <iostream>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <Line.hpp>
#include <ThreeDSquare.hpp>
#include <boost/thread.hpp>

int WIDTH = 200;
int HEIGHT = 200;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];

int startX = 5;
int startY = 5;
int squareSize = 100;

int updateNumber = 1;

void addPixels() {
    PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
    ThreeDSquare(
        WIDTH,
        Coordinate(50, 50, 0),
        squareSize,
        squareSize / 12.5
    ).draw(PixelBuffer);
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	addPixels();

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
	glutSwapBuffers();

	startX += updateNumber;
	startY += updateNumber;

	if (startX > WIDTH || startY > HEIGHT)
		updateNumber = -1;
	
	if (startX < 0 || startY < 0)
		updateNumber = 1;
}

void idle() {
    glutPostRedisplay();
}

void userInput() {
    while (true) {
        std::cout << "SetSize:\n";
        std::cin >> squareSize;
    }
}

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("EB");

	glutDisplayFunc(display);
    glutIdleFunc(idle);

	boost::thread t(userInput);

    glutMainLoop();

	return 0;
}
