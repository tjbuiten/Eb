#pragma once

#include "Events/event.h"

namespace events {
class EventSubscriber {
    public:
        virtual void OnSubscribedEvent(Event* event) = 0;
};
}