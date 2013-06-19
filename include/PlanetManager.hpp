#ifndef PLANETMANAGER_HPP
#define PLANETMANAGER_HPP

#include <irrlicht.h>
#include <stdio.h>
#include <string>
#include "Planet.hpp"
#include "PlanetManager.hpp"

using namespace irr;

class PlanetManager
{
public:
	PlanetManager(video::IrrlichtDevice* Device);
	~PlanetManager();

	void CreatePlanet(const PlanetDescriptor Planet, const io::path &Texture);

	void SetWireframe(const bool State);

	void LoadSolarSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin);

private:
	video::IVideoDriver*	m_pDriver;
	video::ISceneManager*	m_pSMgr;
	vector<Planet>			m_pPlanets;
};

struct PlanetDescriptor
{
	wchar_t*	Name;

	core::d32	Radius;
	core::d32	Flattening;
	core::f32	Gravity;
};

#endif
