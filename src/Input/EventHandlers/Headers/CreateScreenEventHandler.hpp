#pragma once

#include "InputEventHandler.hpp"
#include "ScreenManager.hpp"
#include "InputEventBus.hpp"
#include "InputEvents.hpp"

class CreateScreenEventHandler: public InputEventHandler {
    private:
        ScreenManager* _screenManager;
	public:
        CreateScreenEventHandler(ScreenManager* screenManager, InputEventBus* inputEventBus): _screenManager(screenManager) {
            inputEventBus->Subscribe(InputEvents::CreateScreen, this);
        };

        void HandleEvent(InputEvents event);
};