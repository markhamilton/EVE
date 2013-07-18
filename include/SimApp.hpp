#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <stdio.h>
#include <string>
#include "Planet.hpp"
#include "PlanetManager.hpp"

class SimApp
{
public:
	SimApp();
	~SimApp();
 
	void start();

protected:
	bool init(const std::string wndTitle);
	void createScene();
	void renderScene();

	PlanetManager*		m_pPlanetManager;

private:
	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
