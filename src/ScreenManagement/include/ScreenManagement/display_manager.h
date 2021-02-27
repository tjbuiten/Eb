#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <list>
#include <vector>
#include "ScreenManagement/screen.h"
#include "Events/eventsubscriber.h"
#include "Events/addscreen_event.h"

namespace screen_management {
class DisplayManager: public events::EventSubscriber {
    public:
        DisplayManager(int argc,char **argv) {
	        glutInit(&argc,argv);
        }

        static void AddScreen(std::pair<int, int> size, const char name[]);
        void StartDisplayLoop();
        void OnSubscribedEvent(std::unique_ptr<events::Event> event) override;
    protected:
    private:
        static std::list<Screen> screens;
        static std::vector<std::unique_ptr<events::Event>> eventQueue;
        static void Display();
};
}