#pragma once

#include <iostream>
#include "InputManagement/commands.h"
#include "Events/assemblyline.h"

namespace input_management {
class InputManager {
    public:
        InputManager(events::AssemblyLine assemblyLine): _assemblyLine(assemblyLine) { }

        void InputLoop();
        void StopInputLoop();
    private:
        events::AssemblyLine _assemblyLine;
        bool runInputLoop;
};
}