#include <iostream>
#include <OpenGL/gl3.h>
#include <GLUT/glut.h>

//Program to create an empty Widdow
void init(){
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	//Line C
	glutInitWindowSize(640,480);
	glutInitWindowPosition(1000,200);
	glutCreateWindow("Simple Window");
}

void display()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
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