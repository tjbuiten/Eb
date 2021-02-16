#include "ScreenManagement/display_manager.h"

namespace screen_management {
std::list<Screen> DisplayManager::screens;

void DisplayManager::Display() {
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

void DisplayManager::OnSubscribedEvent(events::Event* event) {
    if (event->GetType() == events::EventType::ADD_SCREEN) {
    }
}
}