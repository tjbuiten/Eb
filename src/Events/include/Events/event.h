#pragma once

#include "Events/eventtype.h"

namespace events {
class Event {
    public:
        virtual EventType GetType();
    protected:
    private:
};
}