#include "InputManagement/inputmanager.h"

namespace input_management {
void InputManager::InputLoop() {
    runInputLoop = true;
    std::string input = "";

    while (runInputLoop) {
        std::cout << "Please input your desired command:" << "\n" << "> ";
        std::getline(std::cin, input);
        std::cout << "\n";

        events::EventType eventType = Commands::GetEventTypeForString(input);

        std::unique_ptr<events::Event> event = _eventFactory.AssembleEvent(eventType);

        if (event == nullptr)
            continue;
        
        _eventBus.SentEvent(std::move(event));
    }
}

void InputManager::StopInputLoop() {
    runInputLoop = false;
}
}
