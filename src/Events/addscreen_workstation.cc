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
    std::string screenWidth = "100";
    std::string screenHeight = "100";

    std::cout << "Please input your desired screen name:" << "\n" << "> ";
    std::getline(std::cin, screenName);
    std::cout << "\n";

    std::cout << "Please input your desired screen width:" << "\n" << "> ";
    std::getline(std::cin, screenWidth);
    std::cout << "\n";

    std::cout << "Please input your desired screen height:" << "\n" << "> ";
    std::getline(std::cin, screenHeight);
    std::cout << "\n";

    event->SetName(screenName);
    event->SetSize(std::pair<int, int>(std::stoi(screenWidth), std::stoi(screenHeight)));

    return std::make_unique<AddScreenEvent>(*event);
}
}