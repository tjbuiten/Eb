#include "InputEventBus.hpp"

void InputEventBus::Subscribe(InputEvents event, InputEventHandler* eventHandler) {
    std::list<InputEventHandler*>* eventHandlerList = this->GetListForEvent(event);

    if (eventHandlerList == NULL) {
        eventHandlerList = new std::list<InputEventHandler*>();
    }

    std::cout << "Registered eventhandler for event: " << event << "\n";
    eventHandlerList->push_back(eventHandler);

    this->eventHandlerMap.insert(
        std::pair<InputEvents, std::list<InputEventHandler*> >(
            event,
            *eventHandlerList
        )
    );
}

void InputEventBus::Unsubscribe(InputEvents event, InputEventHandler* eventHandler) {
    if (this->eventHandlerMap.find(event) == this->eventHandlerMap.end())
        return;

    this->eventHandlerMap[event].remove(eventHandler);
}

void InputEventBus::SentEvent(InputEvents event) {
    std::list<InputEventHandler*>* eventHandlerList = this->GetListForEvent(event);

    if (eventHandlerList == NULL) {
        std::cout << "No handlers for event: " << event << "\n";
        return;
    }
    
    for (InputEventHandler* eventHandler : *eventHandlerList) {
        std::cout << "Should handle event\n";
        eventHandler->HandleEvent(event);
    }
}

std::list<InputEventHandler*>* InputEventBus::GetListForEvent(InputEvents event) {
    auto iterator = this->eventHandlerMap.find(event);

    if (iterator != this->eventHandlerMap.end()) {
        return &iterator->second;
    }
    
    return NULL;
}