#include "Glut.hpp"
#include <iostream>
#include <unistd.h>
#include <boost/thread.hpp>
#include "Vector2.hpp"
#include "ScreenManager.hpp"
#include "InputManager.hpp"
#include "InputEventBus.hpp"
#include "ImplementedInputEventHandler.hpp"
#include "InputEventMap.hpp"

int WIDTH = 200;
int HEIGHT = 200;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
ScreenManager* screenManager = nullptr;
InputManager* inputManager = nullptr;
InputEventBus* inputEventBus = nullptr;

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";

    inputEventBus = new InputEventBus();
    inputManager = new InputManager(inputEventBus);

    ImplementedInputEventHandler* eventHandler = new ImplementedInputEventHandler();
    ImplementedInputEventHandler* eventHandlerTwo = new ImplementedInputEventHandler();

    inputEventBus->Subscribe(InputEvents::Line, eventHandler);
    inputEventBus->Subscribe(InputEvents::Circle, eventHandler);

    boost::thread inputThread(inputManager->StartInputLoop);

    screenManager = new ScreenManager(argc, argv);

    screenManager->CreateScreen("ScreenOne", Vector2<int>(&WIDTH, &HEIGHT));
    screenManager->CreateScreen("ScreenTwo", Vector2<int>(&WIDTH, &HEIGHT));

    screenManager->StartDisplayLoop();

    inputManager->StopInputLoop();

    inputThread.join();

	return 0;
}
