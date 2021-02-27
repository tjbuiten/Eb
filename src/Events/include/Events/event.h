#pragma once

#include "Events/eventtype.h"

namespace events {
class Event {
    public:
        virtual EventType GetType() = 0;
    protected:
    private:
};
}