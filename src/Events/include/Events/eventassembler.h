#pragma once

#include <iostream>
#include "Events/eventtype.h"
#include "Events/event.h"

namespace events {
class EventAssembler {
    public:
        virtual ~EventAssembler() {}
        virtual std::unique_ptr<Event> AssembleEvent(EventType type) = 0;
};
}
