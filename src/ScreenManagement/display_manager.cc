#include "ScreenManagement/display_manager.h"
#include <iostream>

namespace screen_management {
std::list<Screen> DisplayManager::screens;
std::list<events::EventType> DisplayManager::eventQueue;

void DisplayManager::Display() {
    for (events::EventType event : eventQueue) {
        if (event == events::EventType::ADD_SCREEN) {
            char screenName[] = "IMGOD";
            AddScreen(std::pair<int, int>(100, 100), screenName);
        }
    }

    eventQueue = {};

    for (Screen screen: screens) {
        screen.ClearScreen();
        screen.Display();
    }

    glutPostRedisplay();
}

void DisplayManager::StartDisplayLoop() {
    glutMainLoop();
}

void DisplayManager::AddScreen(std::pair<int, int> size, char screenName[]) {
    Screen _screen {size, screenName};
    glutDisplayFunc(Display);

    screens.push_back(_screen);
}

void DisplayManager::OnSubscribedEvent(std::unique_ptr<events::Event> event) {
    eventQueue.push_back(events::EventType::ADD_SCREEN);
}
}