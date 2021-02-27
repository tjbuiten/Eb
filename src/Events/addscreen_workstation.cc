#include "Events/addscreen_workstation.h"

namespace events {
std::unique_ptr<Event> AddScreenWorkstation::OnSubscribedEvent(std::unique_ptr<Event> event) {
    return AddScreenNameToEvent((AddScreenEvent*) &event);
}

std::unique_ptr<Event> AddScreenWorkstation::OnSubscribedEvent(EventType eventType) {
    return AddScreenNameToEvent(new AddScreenEvent());
}

std::unique_ptr<Event> AddScreenWorkstation::AddScreenNameToEvent(AddScreenEvent* event) {
    std::string screenName = "";

    std::cout << "Please input your desired screen name:" << "\n" << "> ";
    std::getline(std::cin, screenName);
    std::cout << "\n";

    event->SetName(screenName);

    return std::make_unique<AddScreenEvent>(*event);
}
}