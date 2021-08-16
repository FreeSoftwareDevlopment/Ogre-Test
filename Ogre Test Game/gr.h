#pragma once
#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreInput.h>
#include <stdio.h>

class MyTestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener
{
private:
    Ogre::SceneManager* scnMgr;
public:
    MyTestApp() : OgreBites::ApplicationContext("OgreTutorialApp") {}
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    void setup();
};
