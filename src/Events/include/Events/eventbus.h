#pragma once

#include <map>
#include <list>
#include "Events/eventtype.h"
#include "Events/event.h"
#include "Events/eventsubscriber.h"

namespace events {
class EventBus {
    public:
        void Subscribe(EventType eventType, EventSubscriber* eventSubscriber);
        void SentEvent(std::unique_ptr<events::Event> event);
    protected:
    private:
        std::map<EventType, std::list<EventSubscriber*>> subscribers;
};
}