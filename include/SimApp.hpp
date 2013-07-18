#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <stdio.h>
#include <string>
#include <irrlicht.h>
#include "Planet.hpp"
#include "PlanetManager.hpp"

using namespace std;
using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace io;
using namespace gui;

class SimApp : public IEventReceiver
{
public:
	SimApp();
	~SimApp();
 
	void start();
	void shutdown();

	virtual bool OnEvent(const SEvent& event);

protected:
	bool init(const stringw wndTitle);
	void createScene();
	void updateScene();

	IrrlichtDevice*		m_pDevice;
	ILogger*			m_pLog;
	IVideoDriver* 		m_pDriver;
	ISceneManager* 		m_pSMgr;

	ICameraSceneNode* 	m_pCamera;

	PlanetManager*		m_pPlanetManager;

private:
	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif