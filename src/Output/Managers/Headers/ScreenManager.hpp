#pragma once

#include "InputEventHandler.hpp"
#include "Glut.hpp"
#include <vector>
#include <list>
#include "Vector2.hpp"
#include "Screen.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class ScreenManager: public InputEventHandler {
    private:
        static std::vector<Screen> screens;
        static std::list<InputEvents> eventQueue;

        void UpdateScreens();
        void HandleEventQueue();
	public:
        ScreenManager(int argc,char **argv) {
	        glutInit(&argc,argv);
        }

        static void CreateScreen(std::string screenName, Vector2<int> size);
        void StartDisplayLoop();
        void HandleEvent(InputEvents event);

        static void Display();
};