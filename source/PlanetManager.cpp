// TODO: Potentially turn this into a scene manager

#include "PlanetManager.hpp"

// PlanetManager::PlanetManager(IrrlichtDevice* Device)
// {
// 	m_pDevice			= Device;
// 	m_pDriver 			= Device->getVideoDriver();
// 	m_pSMgr 			= Device->getSceneManager();

// 	m_pShowWireframe 	= false;
// 	m_pShowBoundingBox 	= false;
// 	m_pShowNormal 		= false;
// 	m_pShowVelocity 	= false;
// }

PlanetManager::~PlanetManager()
{

}
void PlanetManager::addPlanet(const Ogre::String Name, const Ogre::PreciseReal Radius, const Ogre::Vector3 Origin)
{
	Planet* p = new Planet(/*m_pDevice, Name, Texture, Radius*/);
// 	m_pPlanetList.push_back(p);
}

// void PlanetManager::showWireframe(const bool State)
// {
// 	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
// 		m_pPlanetList[ii]->showWireframe(State);

// 	m_pShowWireframe = State;
// }

// void PlanetManager::showBoundingBox(const bool State)
// {
// 	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
// 		m_pPlanetList[ii]->showBoundingBox(State);

// 	m_pShowBoundingBox = State;
// }

// void PlanetManager::showNormal(const bool State)
// {
// 	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
// 		m_pPlanetList[ii]->showNormal(State);

// 	m_pShowNormal = State;
// }

// void PlanetManager::showVelocity(const bool State)
// {
// 	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
// 		m_pPlanetList[ii]->showVelocity(State);

// 	m_pShowVelocity = State;
// }

// void PlanetManager::loadSystem(const io::path &XmlFile, const Ogre::Vector3 RelativeOrigin)
// {
// 	// TODO: Load a system and place all the objects
// }
