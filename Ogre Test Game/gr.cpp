#include "gr.h"
bool MyTestApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
	{
		getRoot()->queueEndRendering();
	}
	return true;
}

Ogre::SceneNode* n(const char* g, Ogre::SceneManager* scnMgr) {
	Ogre::Entity* ent = scnMgr->createEntity(g);
	Ogre::SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	return node;
}

void MyTestApp::setup()
{
	// do not forget to call the base first
	OgreBites::ApplicationContext::setup();

	// register for input events
	addInputListener(this);

	// get a pointer to the already created root
	Ogre::Root* root = getRoot();
	scnMgr = root->createSceneManager();

	// register our scene with the RTSS
	Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);

	// without light we would just get a black screen    
	Ogre::Light* light = scnMgr->createLight("MainLight");
	Ogre::SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 10, 15);
	lightNode->attachObject(light);

	// also need to tell where we are
	Ogre::SceneNode* camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(0, 0, 15);
	camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

	// create the camera
	Ogre::Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5); // specific to this sample
	cam->setAutoAspectRatio(true);
	camNode->attachObject(cam);

	// and tell it to render into the main window
	getRenderWindow()->addViewport(cam);
	scnMgr->setShadowTechnique(Ogre::ShadowTechnique::SHADOWTYPE_STENCIL_ADDITIVE);
	scnMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);

	{
		// finally something to render
		auto node = n("Sinbad.mesh", scnMgr);
		node->scale(Ogre::Vector3(0.2, 0.2, 0.2));
		node->roll(Ogre::Degree(20));
		node->setPosition(Ogre::Vector3(-3, -4, -3));
	}
	{
		// finally something to render
		auto node = n("fish.mesh", scnMgr);
		node->scale(Ogre::Vector3(0.4, 0.4, 0.4));
		node->roll(Ogre::Degree(-90));
		node->setPosition(Ogre::Vector3(0, 3, 3));
	}

	{
		// finally something to render
		auto node = n("razor.mesh", scnMgr);
		node->scale(Ogre::Vector3(0.4, 0.4, 0.4));
		node->roll(Ogre::Degree((90 / 1002) * -1));
		node->setPosition(Ogre::Vector3(1, 0, -50));
	}
}
