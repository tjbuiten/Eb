#include "ScreenManagement/display_manager.h"
#include <iostream>

namespace screen_management {
std::list<Screen> DisplayManager::screens;
std::vector<std::unique_ptr<events::Event>> DisplayManager::eventQueue;

void DisplayManager::Display() {
    auto eventQueueSize = eventQueue.size();

    if (eventQueueSize > 0) {
        for (int i = 0; i < eventQueueSize; i++) {
            if (eventQueue[i]->GetType() == events::EventType::ADD_SCREEN) {
                events::AddScreenEvent* addScreenEvent = dynamic_cast<events::AddScreenEvent*>(eventQueue[i].get());
                AddScreen(std::pair<int, int>(100, 100), addScreenEvent->GetName().c_str());
            }
        }
        
        eventQueue.erase(eventQueue.begin(), eventQueue.begin() + eventQueueSize);
    }

    for (Screen screen: screens) {
        screen.ClearScreen();
        screen.Display();
    }

    glutPostRedisplay();
}

void DisplayManager::StartDisplayLoop() {
    glutMainLoop();
}

void DisplayManager::AddScreen(std::pair<int, int> size, const char screenName[]) {
    Screen _screen {size, screenName};
    glutDisplayFunc(Display);

    screens.push_back(_screen);
}

void DisplayManager::OnSubscribedEvent(std::unique_ptr<events::Event> event) {
    eventQueue.push_back(std::move(event));
}
}