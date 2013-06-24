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

void PlanetManager::showWireframe(const bool State)
{
	// TODO: Loop through all planets and set their material flag to render wireframe
}

void PlanetManager::showBoundingBox(const bool State)
{
	// TODO: Loop through all the planets and enable their bounding boxes
}

void PlanetManager::showNormal(const bool State)
{
	// TODO: Loop through all the planets and show their normals
}

void PlanetManager::showVelocity(const bool State)
{
	// TODO: Loop through all the planets and show their velocity paths
}

void PlanetManager::loadSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin)
{
	// TODO: Load a system and place all the objects
}
