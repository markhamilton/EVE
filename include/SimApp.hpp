#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string>
#include "Planet.hpp"
#include "PlanetManager.hpp"

class SimApp
{
public:
	SimApp();
	~SimApp();
 
	bool init(const std::string wndTitle);
	void createScene();

	void start();
	void renderScene();

protected:
	PlanetManager*		m_pPlanetManager;

private:
	bool		m_bSettingsMode;
    bool 		m_bQuit;

    bool		m_bRMouseDown;
    bool		m_bLMouseDown;
};
 
#endif
