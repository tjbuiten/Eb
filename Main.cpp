#include <thread>
#include <iostream>
#include "ScreenManagement/display_manager.h"
#include "InputManagement/inputmanager.h"
#include "Events/addscreen_workstation.h"
#include "Events/eventtype.h"

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
    
    screen_management::DisplayManager _displayManager {argc, argv};

    char screenName[] = "Test screen";

    events::EventBus _eventBus = events::EventBus();
    events::AssemblyLine _assemblyLine = events::AssemblyLine(_eventBus);

    events::AddScreenWorkstation _addScreenWorkstation = events::AddScreenWorkstation();

    _assemblyLine.AddWorkstation(events::EventType::ADD_SCREEN, &_addScreenWorkstation);

    input_management::InputManager _inputManager = input_management::InputManager(_assemblyLine);

    _displayManager.AddScreen(std::pair<int, int>(100, 100), screenName);

    _eventBus.Subscribe(events::EventType::ADD_SCREEN, &_displayManager);

    std::thread input (&input_management::InputManager::InputLoop, _inputManager);
    _displayManager.StartDisplayLoop();

	return 0;
}
