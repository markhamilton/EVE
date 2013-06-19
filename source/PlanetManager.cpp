#include "PlanetManager.hpp"

PlanetManager::PlanetManager(video::IrrlichtDevice* Device)
{
	m_pDriver = Device->getVideoDriver();
	m_pSMgr = Device->getSceneManager();
}

PlanetManager::~PlanetManager()
{

}

void PlanetManager::CreatePlanet(const PlanetDescriptor Planet, const io::path &Texture)
{

}

void PlanetManager::SetWireframe(const bool State)
{
	// TODO: Loop through all planets and set their material flag to render wireframe
}

void LoadSolarSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin)
{
	// TODO: Load a solar system and place all the objects 	
}