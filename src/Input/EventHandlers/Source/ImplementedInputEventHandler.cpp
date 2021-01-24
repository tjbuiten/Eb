#include "ImplementedInputEventHandler.hpp"

#include <iostream>

void ImplementedInputEventHandler::HandleEvent(InputEvents event) {
    std::cout << "We've received a event\n";
}