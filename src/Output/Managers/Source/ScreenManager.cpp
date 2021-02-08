#include "ScreenManager.hpp"

std::vector<Screen> ScreenManager::screens;
std::list<InputEvents> ScreenManager::eventQueue;

void ScreenManager::Display() {
    for (InputEvents event : eventQueue) {
        int x = 100, y = 100;

        if (event == InputEvents::CreateScreen) {
            CreateScreen(std::to_string(rand()), Vector2<int>(&x, &y));
        }

        eventQueue.pop_front();
    }

    for (Screen screen: screens) {
        screen.ClearScreen();
        screen.UpdateScreen();
        screen.Display();
    }

    glutPostRedisplay();
}

void ScreenManager::CreateScreen(std::string screenName, Vector2<int> size) {
    Screen screen = Screen(screenName, size);

    screens.push_back(screen);

    glutSetWindow(screen.GetWindowId());
    glutDisplayFunc(Display);
}

void ScreenManager::StartDisplayLoop() {
    glutMainLoop();
}

void ScreenManager::HandleEvent(InputEvents event) {
    this->eventQueue.push_back(event);
}