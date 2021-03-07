#include <thread>
#include <iostream>
#include "ScreenManagement/display_manager.h"
#include "InputManagement/inputmanager.h"
#include "Events/eventtype.h"
#include "Events/eventfactory.h"
#include "Events/addscreen_eventassembler.h"

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
    
    screen_management::DisplayManager _displayManager {argc, argv};

    char screenName[] = "Test screen";

    events::EventBus _eventBus = events::EventBus();
    events::EventFactory _eventFactory = events::EventFactory();
    events::AddScreenEventAssembler _addScreenEventAssembler = events::AddScreenEventAssembler();

    _eventFactory.Subscribe(events::EventType::ADD_SCREEN, &_addScreenEventAssembler);
    _displayManager.AddScreen(std::pair<int, int>(100, 100), screenName);
    _eventBus.Subscribe(events::EventType::ADD_SCREEN, &_displayManager);

    input_management::InputManager _inputManager = input_management::InputManager(_eventFactory, _eventBus);

    std::thread input (&input_management::InputManager::InputLoop, _inputManager);
    _displayManager.StartDisplayLoop();

	return 0;
}
