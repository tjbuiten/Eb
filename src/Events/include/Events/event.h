#pragma once

#include "Events/eventtype.h"

namespace events {
class Event {
    public:
        virtual ~Event() {}
        virtual EventType GetType() = 0;
    protected:
    private:
};
}