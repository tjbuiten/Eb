#include "Events/eventbus.h"

#include <iostream>

namespace events {
void EventBus::Subscribe(EventType eventType, EventSubscriber* eventSubscriber) {
    subscribers[EventType::ADD_SCREEN].push_back(eventSubscriber);
}

void EventBus::SentEvent(std::unique_ptr<events::Event> event) {
    for (EventSubscriber* subscriber : subscribers[EventType::ADD_SCREEN]) {
        if (subscriber == nullptr) {
            subscribers[event->GetType()].remove(subscriber);
        }

        subscriber->OnSubscribedEvent(move(event));
    };
}
}