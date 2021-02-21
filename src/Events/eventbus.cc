#include "Events/eventbus.h"

#include <iostream>

namespace events {
void EventBus::Subscribe(EventType eventType, EventSubscriber* eventSubscriber) {
    subscribers[eventType].push_back(eventSubscriber);
}

void EventBus::SentEvent(Event* event) {
    std::cout << "IN SEND EVENT FUNCTION\n";

    std::cout << event->GetType() << "\n";
    for (EventSubscriber* subscriber : subscribers[event->GetType()]) {
        if (subscriber == nullptr) {
            std::cout << "REMOVING SUB\n";
            subscribers[event->GetType()].remove(subscriber);
        }
        std::cout << "SENDING EVENT OUT\n";
        subscriber->OnSubscribedEvent(event);
    };
}
}