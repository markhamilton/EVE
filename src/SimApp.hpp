#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <stdio.h>
#include <string>
#include <OGRE/Ogre.h>
#include "Planet.hpp"
#include "PlanetManager.hpp"

using namespace Ogre;
using namespace std;

class SimApp : public FrameListener
{
public:
	SimApp();
	~SimApp();
 
	void start();
	void shutdown();

	//virtual bool OnEvent(const SEvent& event);

protected:
	bool init(const String wndTitle);
	void createScene();
	void updateScene();

	Root*				m_pRoot;
	RenderWindow*		m_pWindow;
	SceneManager*		m_pSMgr;
	Camera*				m_pCamera;
	Viewport*			m_pView;

	//ILogger*			m_pLog;


	PlanetManager*		m_pPlanetManager;

private:
	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
