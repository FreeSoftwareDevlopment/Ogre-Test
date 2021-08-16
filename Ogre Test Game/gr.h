#pragma once
#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreInput.h>

class MyTestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
public:
    MyTestApp() : OgreBites::ApplicationContext("OgreTutorialApp") {}
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    void setup();
};
