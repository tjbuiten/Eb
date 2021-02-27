#pragma once

#include "Events/workstation.h"
#include "Events/addscreen_event.h"
#include <iostream>

namespace events {
class AddScreenWorkstation : public Workstation {
    public:
        std::unique_ptr<Event> OnSubscribedEvent(std::unique_ptr<Event> event) override;
        std::unique_ptr<Event> OnSubscribedEvent(EventType eventType) override;
    private:
        std::unique_ptr<Event> AddScreenNameToEvent(AddScreenEvent* event);
};
}