#ifndef PLANETMANAGER_HPP
#define PLANETMANAGER_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include <irrlicht.h>
#include "Planet.hpp"

using namespace std;
using namespace irr;
using namespace video;
using namespace scene;
using namespace core;

class PlanetManager
{
public:
	PlanetManager();
	~PlanetManager();

	void addPlanet(const io::path &Texture);

	void setWireframe(const bool State);

	void loadSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin);

private:
	IVideoDriver*			m_pDriver;
	ISceneManager*			m_pSMgr;
	// vector<Planet>			m_pPlanetList;
};

#endif
