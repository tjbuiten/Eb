#pragma once
#include "Glut.hpp"
#include <vector>
#include "Vector2.hpp"
#include "Screen.hpp"

class ScreenManager {
    private:
        static std::vector<Screen> screens;
	public:
        ScreenManager(int argc,char **argv) {
	        glutInit(&argc,argv);
        }

        void CreateScreen(std::string screenName, Vector2<int> size);
        void StartDisplayLoop();

        static void Display();
};