#pragma once

#include <map>
#include <list>
#include "Events/eventtype.h"
#include "Events/event.h"
#include "Events/eventassembler.h"

namespace events {
class EventFactory {
    public:
        void Subscribe(EventType eventType, EventAssembler* eventAssembler);
        std::unique_ptr<Event> AssembleEvent(EventType eventType);
    protected:
    private:
        std::map<EventType, EventAssembler*> subscribers;
};
}
