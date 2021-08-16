// Ogre Test Game.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "Ogre Test Game.h"

using namespace std;

int main()
{
	puts("Hello OGRE.");
    MyTestApp app;
    app.initApp();
    app.getRoot()->startRendering();
    app.closeApp();
    return 0;
	return 0;
}
