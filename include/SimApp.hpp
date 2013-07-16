#ifndef SIMAPP_HPP
#define SIMAPP_HPP

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
 
	bool init(const std::string wndTitle);
	void createScene();
	void exit();

	void start();
	void pause();
	void resume();
	void update(const double timeSinceLastFrame);

protected:
	PlanetManager*		m_pPlanetManager;

private:
	bool initLogging();
	bool initRoot(const std::string wndTitle);
	bool initConfig();
	bool initGUI();

	void updateCamera();
	void updateInput();

	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
