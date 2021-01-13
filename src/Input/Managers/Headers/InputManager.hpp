#pragma once

#include <unistd.h>
#include <iostream>

class InputManager {
    private:
        static bool handleInput;
        static std::string lastInput;
	public:
        InputManager() {}

        static void StartInputLoop();

        void StopInputLoop();
};