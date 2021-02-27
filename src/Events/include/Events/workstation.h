#pragma once

#include "Events/event.h"
#include "iostream"

namespace events {
class Workstation {
    public:
        virtual std::unique_ptr<Event> OnSubscribedEvent(std::unique_ptr<Event> event) = 0;
        virtual std::unique_ptr<Event> OnSubscribedEvent(EventType eventType) = 0;
};
}