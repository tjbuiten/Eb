#include "Events/eventfactory.h"

#include <iostream>

namespace events {
void EventFactory::Subscribe(EventType eventType, EventAssembler* eventAssembler) {
    subscribers[eventType] = eventAssembler;
}

std::unique_ptr<Event> EventFactory::AssembleEvent(EventType eventType) {
    EventAssembler* subscriber = subscribers[eventType];

    if (subscriber == nullptr) {
        return nullptr;
    }

    return subscriber->AssembleEvent(eventType);
}
}
