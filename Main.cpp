#include <iostream>
#include "ScreenManagement/display_manager.h"

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";
    
    screen_management::DisplayManager _displayManager {argc, argv};

    char screenName[] = "Test screen";

    _displayManager.AddScreen(std::pair<int, int>(100, 100), screenName);
    _displayManager.StartDisplayLoop();

	return 0;
}
