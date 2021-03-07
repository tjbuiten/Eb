#pragma once

#include <iostream>
#include "InputManagement/commands.h"
#include "Events/eventfactory.h"
#include "Events/eventbus.h"

namespace input_management {
class InputManager {
    public:
        InputManager(events::EventFactory eventFactory, events::EventBus eventBus):
            _eventFactory(eventFactory),
            _eventBus(eventBus) { }

        void InputLoop();
        void StopInputLoop();
    private:
        events::EventFactory _eventFactory;
        events::EventBus _eventBus;
        bool runInputLoop;
};
}
