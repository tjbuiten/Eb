#pragma once

#include <map>
#include <list>
#include <unistd.h>
#include <iostream>
#include "InputEvents.hpp"
#include "InputEventHandler.hpp"

class InputEventBus {
    private:
        std::map<InputEvents, std::list<InputEventHandler*> > eventHandlerMap;

        std::list<InputEventHandler*>* GetListForEvent(InputEvents event);
	public:
        InputEventBus() {}

        void Subscribe(InputEvents event, InputEventHandler* eventHandler);

        void Unsubscribe(InputEvents event, InputEventHandler* eventHandler);

        void SentEvent(InputEvents event);
};