#include "InputManager.hpp"

bool InputManager::handleInput;
InputEventBus* InputManager::inputEventBus;

void InputManager::StartInputLoop() {
    std::string input;
    handleInput = true;

    while (handleInput) {
        std::cout << "> ";
        std::getline(std::cin, input);
        
        const InputEvents event = InputEventMap::GetEventForString(input);


        if (inputEventBus == nullptr) {
            std::cout << "Missing the eventbus\n";
        }
        else if (event != InputEvents::DEFAULT) {
            inputEventBus->SentEvent(event);
        }
        else {
            std::cout << "Whoops, looks like we couldn't find that command\n";
        }
    }
};

void InputManager::StopInputLoop() {
    this->handleInput = false;
}