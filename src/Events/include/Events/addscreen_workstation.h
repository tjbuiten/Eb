#pragma once

#include "Events/workstation.h"
#include "Events/addscreen_event.h"
#include <iostream>

namespace events {
class AddScreenWorkstation : public Workstation {
    public:
        Event* OnSubscribedEvent(Event* event) override;
        Event* OnSubscribedEvent(EventType eventType) override;
    private:
        Event* AddScreenNameToEvent(AddScreenEvent* event);
};
}