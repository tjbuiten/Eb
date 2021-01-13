#include "InputManager.hpp"

bool InputManager::handleInput;
std::string InputManager::lastInput;

void InputManager::StartInputLoop() {
    handleInput = true;

    while (handleInput) {
        sleep(1);
        std::cout << "SetSize:\n";
        std::cin >> lastInput;
    }
}

void InputManager::StopInputLoop() {
    this->handleInput = false;
}