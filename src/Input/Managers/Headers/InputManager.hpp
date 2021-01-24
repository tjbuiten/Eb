#pragma once

#include <map>
#include <unistd.h>
#include <iostream>
#include "InputEvents.hpp"
#include "InputEventBus.hpp"
#include "InputEventMap.hpp"

class InputManager {
    private:
        static bool handleInput;
        static InputEventBus* inputEventBus;
	public:
        InputManager(InputEventBus* inputEventBus) {
            this->inputEventBus = inputEventBus;
        }

        static void StartInputLoop();

        void StopInputLoop();
};