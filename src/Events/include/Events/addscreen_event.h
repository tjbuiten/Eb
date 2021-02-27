#pragma once

#include <string>
#include "Events/event.h"

namespace events {
class AddScreenEvent: public Event {
    public:
        AddScreenEvent() {
        }

        ~AddScreenEvent() override {

        }

        EventType GetType() override;

        std::string GetName();
        void SetName(std::string name);
    protected:
    private:
        std::string name;
};
}