#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <OGRE/OgreCamera.h>
#include <OGRE/OgreEntity.h>
#include <OGRE/OgreLogManager.h>
#include <OGRE/OgreOverlay.h>
#include <OGRE/OgreOverlayElement.h>
#include <OGRE/OgreOverlayManager.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreViewport.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreConfigFile.h>
 
#include <OIS/OISEvents.h>
#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>

#include <stdio.h>
#include <string>
#include "EventHandler.hpp"
#include "Planet.hpp"
#include "PlanetManager.hpp"

class SimApp
{
public:
	SimApp();
	~SimApp();
 
	bool init(const Ogre::String wndTitle);
	void createScene();
	void exit();

	void start();
	void pause();
	void resume();
	void update(const double timeSinceLastFrame);
 

	bool keyPressed();
	bool keyReleased();
 
	bool mouseMoved();
	bool mousePressed();
	bool mouseReleased();

 	void onLeftPressed();

protected:
	Ogre::Root* 		m_pRoot;
	Ogre::SceneManager* m_pSmgr;
	Ogre::RenderWindow* m_pWindow;
	Ogre::Camera*		m_pCamera;
	Ogre::Viewport*		m_pViewport;
	Ogre::Log*			m_pLog;
	Ogre::Timer*		m_pTimer;

	// IGUIStaticText*		m_pFpsCounter;

	OIS::InputManager*	m_pInputMgr;
	OIS::Keyboard*		m_pKeyboard;
	OIS::Mouse*			m_pMouse;

	PlanetManager*		m_pPlanetManager;

private:
	void buildGUI();
	void updateCamera();
	void getInput();

	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
