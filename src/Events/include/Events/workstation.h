#pragma once

#include "Events/event.h"

namespace events {
class Workstation {
    public:
        virtual Event* OnSubscribedEvent(Event* event) = 0;
        virtual Event* OnSubscribedEvent(EventType eventType) = 0;
};
}