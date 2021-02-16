#pragma once

#include <map>
#include <list>
#include "Events/eventtype.h"
#include "Events/event.h"
#include "Events/eventsubscriber.h"

namespace events {
class EventBus {
    public:
        virtual void Subscribe(EventType eventType, EventSubscriber* eventSubscriber) = 0;
        virtual void SentEvent(Event event) = 0;
    protected:
    private:
        std::map<EventType, std::list<EventSubscriber*>> subscribers;
};
}