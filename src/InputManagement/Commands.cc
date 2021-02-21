#include "InputManagement/commands.h"

namespace input_management {
std::map<std::string, events::EventType> const Commands::eventMap = {
    {"create screen", events::EventType::ADD_SCREEN}
};

const events::EventType Commands::GetEventTypeForString(std::string input) {
    events::EventType inputEvent = events::EventType::DEFAULT;

    auto iterator = eventMap.find(input);

    if (iterator != eventMap.end()) {
        inputEvent = iterator->second;
    }

    return inputEvent;
}
}