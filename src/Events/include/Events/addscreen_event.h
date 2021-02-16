#pragma once

#include <string>
#include "Events/event.h"

namespace events {
class AddScreenEvent: Event {
    public:
        AddScreenEvent(std::string name) {
            this->name = name;
        }

        EventType GetType() override;

        std::string GetName();
    protected:
    private:
        std::string name;
};
}