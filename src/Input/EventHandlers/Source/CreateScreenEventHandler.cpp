#include "CreateScreenEventHandler.hpp"

void CreateScreenEventHandler::HandleEvent(InputEvents event) {
    _screenManager->HandleEvent(event);
}