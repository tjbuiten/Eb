#pragma once

#include "InputEvents.hpp"

class InputEventHandler {
	public:
        virtual void HandleEvent(InputEvents event) = 0;
};