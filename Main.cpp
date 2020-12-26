#include <iostream>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>

int WIDTH = 400;
int HEIGHT = 400;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];

//Program to create an empty Widdow
void init(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Simple Window");
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
    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
	glutSwapBuffers();
}

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
	glutInit(&argc,argv);
	init();

    drawPixel(50,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,150,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(50,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,151,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(50,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,152,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(50,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,153,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(50,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,154,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(50,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(51,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(52,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(53,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(54,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);
    drawPixel(55,155,255,255,255,PixelBuffer, WIDTH, HEIGHT);

	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}