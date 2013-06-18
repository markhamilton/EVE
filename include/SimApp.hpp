#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <irrlicht.h>
#include <stdio.h>
#include <string>
#include "Planet.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class SimApp
{
public:
	SimApp();
	~SimApp();
 
	bool init(const wchar_t* wndTitle);
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
	IrrlichtDevice* 	m_pDevice;
	IVideoDriver* 		m_pDriver;
 	ISceneManager* 		m_pSmgr;
	IGUIEnvironment*	m_pGui;

	ICameraSceneNode*	m_pModelingCam;

private:
	// void buildGUI();

	void updateCamera();
	void getInput();

	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
