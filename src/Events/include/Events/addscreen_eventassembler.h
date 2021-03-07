#pragma once

#include "Events/eventassembler.h"
#include "Events/addscreen_event.h"

namespace events {
class AddScreenEventAssembler : public EventAssembler {
    public:
        AddScreenEventAssembler() {

        }

        ~AddScreenEventAssembler() override {

        }

        std::unique_ptr<Event> AssembleEvent(EventType type) override;
};
}
