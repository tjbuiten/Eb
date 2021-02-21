#pragma once

#include <map>
#include <string>
#include "Events/eventtype.h"

namespace input_management {
class Commands {
    private:
        static std::map<std::string, events::EventType> const eventMap;
    public:
        static const events::EventType GetEventTypeForString(std::string input);
};
}