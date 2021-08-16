#include "Ogre Test Game.h"

#ifdef WIN32
#include <Windows.h>
#pragma comment(lib, "user32.lib")
#endif

using namespace std;

int main()
{
	puts("Hello OGRE.");
#ifdef WIN32
    SetConsoleTitle("Hello OGRE.");
#endif
    MyTestApp app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();
    return 0;
	return 0;
}
