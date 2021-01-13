#include "Glut.hpp"
#include <iostream>
#include <unistd.h>
#include <boost/thread.hpp>
#include "Vector2.hpp"
#include "ScreenManager.hpp"
#include "InputManager.hpp"

int WIDTH = 200;
int HEIGHT = 200;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
ScreenManager* screenManager = nullptr;
InputManager* inputManager = nullptr;

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";

    inputManager = new InputManager();

    boost::thread inputThread(inputManager->StartInputLoop);

    screenManager = new ScreenManager(argc, argv);

    screenManager->CreateScreen("ScreenOne", Vector2<int>(&WIDTH, &HEIGHT));
    screenManager->CreateScreen("ScreenTwo", Vector2<int>(&WIDTH, &HEIGHT));

    screenManager->StartDisplayLoop();

    inputManager->StopInputLoop();

    inputThread.join();

	return 0;
}
