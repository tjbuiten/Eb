#pragma once

#include <string>
#include "Events/event.h"

namespace events {
class AddScreenEvent: public Event {
    public:
        AddScreenEvent() {
        }

        EventType GetType();

        std::string GetName();
        void SetName(std::string name);
    protected:
    private:
        std::string name;
};
}