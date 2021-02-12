#include <iostream>
#include "ScreenManagement/screen.h"

int main(int argc,char **argv)
{
    std::cout << "Hello, world!\n";

    screen_management::Screen screen{}; 
    screen.test();

	return 0;
}
