#pragma once

#include "InputEventHandler.hpp"
#include "InputEvents.hpp"

class ImplementedInputEventHandler: public InputEventHandler {
	public:
        void HandleEvent(InputEvents event);
};