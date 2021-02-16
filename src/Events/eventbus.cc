#include "Events/eventbus.h"

namespace events {
void EventBus::Subscribe(EventType eventType, EventSubscriber* eventSubscriber) {
    subscribers[eventType].push_back(eventSubscriber);
}

void EventBus::SentEvent(Event event) {
    for (EventSubscriber* subscriber : subscribers[event.GetType()]) {
        if (subscriber == nullptr) {
            subscribers[event.GetType()].remove(subscriber);
        }
        subscriber->OnSubscribedEvent(&event);
    };
}
}