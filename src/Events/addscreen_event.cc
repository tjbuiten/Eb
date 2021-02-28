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

std::pair<int, int> AddScreenEvent::GetSize() {
    return size;
}

void AddScreenEvent::SetSize(std::pair<int, int> size) {
    this->size = size;
}
}