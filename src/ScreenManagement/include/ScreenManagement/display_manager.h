#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <list>
#include "ScreenManagement/screen.h"
#include "Events/eventsubscriber.h"

namespace screen_management {
class DisplayManager: public events::EventSubscriber {
    public:
        DisplayManager(int argc,char **argv) {
	        glutInit(&argc,argv);
        }

        static void AddScreen(std::pair<int, int> size, char name[]);
        void StartDisplayLoop();
        void OnSubscribedEvent(events::Event* event) override;
    protected:
    private:
        static std::list<Screen> screens;
        static std::list<events::EventType> eventQueue;
        static void Display();
};
}