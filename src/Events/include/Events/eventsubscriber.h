#pragma once

#include "Events/event.h"

namespace events {
class EventSubscriber {
    public:
        virtual void OnSubscribedEvent(std::unique_ptr<events::Event> event) = 0;
};
}
