#include "InputEventMap.hpp"

std::map<std::string, InputEvents> const InputEventMap::inputMap = {
    {"line", InputEvents::Line},
    {"circle", InputEvents::Circle},
    {"square", InputEvents::Square}
};

const InputEvents InputEventMap::GetEventForString(std::string str) {
    InputEvents inputEvent = InputEvents::DEFAULT;

    auto iterator = inputMap.find(str);

    if (iterator != inputMap.end()) {
        inputEvent = iterator->second;
    }

    return inputEvent;
}