#include "Events/addscreen_workstation.h"

namespace events {
Event* AddScreenWorkstation::OnSubscribedEvent(Event* event) {
    return AddScreenNameToEvent((AddScreenEvent*) &event);
}

Event* AddScreenWorkstation::OnSubscribedEvent(EventType eventType) {
    return AddScreenNameToEvent(new AddScreenEvent());
}

Event* AddScreenWorkstation::AddScreenNameToEvent(AddScreenEvent* event) {
    std::string screenName = "";

    std::cout << "Please input your desired screen name:" << "\n" << "> ";
    std::getline(std::cin, screenName);
    std::cout << "\n";

    event->SetName(screenName);

    return event;
}
}