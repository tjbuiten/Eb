#include "Events/addscreen_event.h"

namespace events {
EventType AddScreenEvent::GetType() {
    return EventType::ADD_SCREEN;
}

std::string AddScreenEvent::GetName() {
    return name;
}

void AddScreenEvent::SetName(std::string name) {
    this->name = name;
}
}