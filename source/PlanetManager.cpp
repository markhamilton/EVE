// TODO: Potentially turn this into a scene manager

#include "PlanetManager.hpp"

PlanetManager::PlanetManager(IrrlichtDevice* Device)
{
	m_pDevice		= Device;
	m_pDriver 		= Device->getVideoDriver();
	m_pSMgr 		= Device->getSceneManager();
}

PlanetManager::~PlanetManager()
{

}
void PlanetManager::addPlanet(const stringw Name, const io::path &Texture, const f32 Radius, const vector3df Origin)
{
	Planet* p = new Planet(m_pDevice, Name, Texture, Radius);
	m_pPlanetList.push_back(p);
}

void PlanetManager::showWireframe(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showWireframe(State);
}

void PlanetManager::showBoundingBox(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showBoundingBox(State);
}

void PlanetManager::showNormal(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showNormal(State);
}

void PlanetManager::showVelocity(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showVelocity(State);
}

void PlanetManager::loadSystem(const io::path &XmlFile, const core::vector3df RelativeOrigin)
{
	// TODO: Load a system and place all the objects
}
