#include "Events/addscreen_eventassembler.h"

namespace events {
std::unique_ptr<Event> AddScreenEventAssembler::AssembleEvent(EventType type) {
    events::AddScreenEvent addScreenEvent = events::AddScreenEvent();
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

    addScreenEvent.SetName(screenName);
    addScreenEvent.SetSize(std::pair<int, int>(std::stoi(screenWidth), std::stoi(screenHeight)));

    return std::make_unique<AddScreenEvent>(addScreenEvent);
}
}
