#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <list>
#include "ScreenManagement/screen.h"

namespace screen_management {
class DisplayManager {
    public:
        DisplayManager(int argc,char **argv) {
	        glutInit(&argc,argv);
        }

        void AddScreen(std::pair<int, int> size, char name[]);
        void StartDisplayLoop();
    protected:
    private:
        static std::list<Screen> screens;
        static void Display();
};
}