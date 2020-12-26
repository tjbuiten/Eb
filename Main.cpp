#include <iostream>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>
#include <unistd.h>

int WIDTH = 200;
int HEIGHT = 200;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];

int startX = 5;
int startY = 5;

int updateNumber = 1;

//Program to create an empty Widdow
void init(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(0,0);
	glutCreateWindow("EB");
}

void drawPixel(int x, int y, int r, int g, int b, GLubyte* pixels, int width, int height)
{
    if (0 <= x && x < width && 0 <= y && y < height) {
        int position = (x + y * width) * 3;
        pixels[position] = r;
        pixels[position + 1] = g;
        pixels[position + 2] = b;
    }
}

void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();

	PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
    drawPixel(startX + 0,startY,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 1,startY,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 2,startY,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 3,startY,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 4,startY,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 0,startY + 1,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 1,startY + 1,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 2,startY + 1,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 3,startY + 1,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 4,startY + 1,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 0,startY + 2,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 1,startY + 2,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 2,startY + 2,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 3,startY + 2,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 4,startY + 2,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 0,startY + 3,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 1,startY + 3,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 2,startY + 3,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 3,startY + 3,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 4,startY + 3,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 0,startY + 4,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 1,startY + 4,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 2,startY + 4,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 3,startY + 4,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(startX + 4,startY + 4,255,255,255,PixelBuffer, WIDTH, HEIGHT);

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
	glutSwapBuffers();

	startX += updateNumber;
	startY += updateNumber;

	if (startX > WIDTH || startY > HEIGHT)
		updateNumber = -1;
	
	if (startX < 0 || startY < 0)
		updateNumber = 1;

	sleep(0.01);

	std::cout << "x: " << startX << "y: " << startY << "\n";
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
	glutInit(&argc,argv);
	init();

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}