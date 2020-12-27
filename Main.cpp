#include <iostream>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <Line.hpp>
#include <ThreeDSquare.hpp>

int WIDTH = 200;
int HEIGHT = 200;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];

int startX = 5;
int startY = 5;

int updateNumber = 1;

void drawPixel(int x, int y, int r, int g, int b, GLubyte* pixels, int width, int height)
{
    if (0 <= x && x < width && 0 <= y && y < height) {
        int position = (x + y * width) * 3;
        pixels[position] = r;
        pixels[position + 1] = g;
        pixels[position + 2] = b;
    }
}

void addPixels() {
    PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
    ThreeDSquare(
        WIDTH,
        Coordinate(50, 50, 0),
        100,
        12
    ).draw(PixelBuffer);
}

void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
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

	glutPostRedisplay();
	sleep(0.01);
}

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("EB");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
