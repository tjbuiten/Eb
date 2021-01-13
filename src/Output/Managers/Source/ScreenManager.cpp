#include "ScreenManager.hpp"
#include <iostream>

std::vector<Screen> ScreenManager::screens;

void ScreenManager::Display() {
    for (Screen screen: screens) {
        screen.ClearScreen();
        screen.UpdateScreen();
        screen.Display();
    }
}

void ScreenManager::CreateScreen(std::string screenName, Vector2<int> size) {
    this->screens.push_back(
        Screen(screenName, size)
    );
    glutDisplayFunc(Display);
}

void ScreenManager::StartDisplayLoop() {
    glutMainLoop();
}