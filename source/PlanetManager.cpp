// TODO: Potentially turn this into a scene manager

#include "PlanetManager.hpp"

PlanetManager::PlanetManager()
{
	m_pDriver = 0;
	m_pSMgr = 0;
}

PlanetManager::~PlanetManager()
{

}
void PlanetManager::addPlanet(const io::path &Texture)
{
	// TODO: Create planet object
}

void PlanetManager::setWireframe(const bool State)
{
	// TODO: Loop through all planets and set their material flag to render wireframe
}

void PlanetManager::loadSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin)
{
	// TODO: Load a system and place all the objects
}
