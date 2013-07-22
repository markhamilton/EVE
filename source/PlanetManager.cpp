// TODO: Potentially turn this into a scene manager

#include "PlanetManager.hpp"

PlanetManager::PlanetManager(IrrlichtDevice* Device)
{
	m_pDevice			= Device;
	m_pDriver 			= Device->getVideoDriver();
	m_pSMgr 			= Device->getSceneManager();

	m_pShowWireframe 	= false;
	m_pShowPointCloud	= false;
	m_pShowLighting 	= true;
	m_pShowOutline 	 	= false;
	m_pShowBoundingBox 	= false;
	m_pShowNormal 		= false;
	m_pShowVelocity 	= false;
}

PlanetManager::~PlanetManager()
{

}
void PlanetManager::addPlanet(const stringw Name, const double Radius, const vector3df Origin)
{
	Planet* p = new Planet(m_pDevice, Name, "../assets/earth.jpg", Radius);
	m_pPlanetList.push_back(p);
}

void PlanetManager::showWireframe(const bool State)
{
	for (int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showWireframe(State);

	// Disable point cloud flags
	if (State) showPointCloud(false);

	m_pShowWireframe = State;
}

void PlanetManager::showPointCloud(const bool State)
{
	for (int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showPointCloud(State);

	// Disable wireframe flags
	if (State) showWireframe(false);

	m_pShowPointCloud = State;
}

void PlanetManager::showLighting(const bool State)
{
	for (int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showLighting(State);

	m_pShowLighting = State;
}

void PlanetManager::showOutline(const bool State)
{
	for (int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showOutline(State);

	m_pShowOutline = State;
}

void PlanetManager::showBoundingBox(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showBoundingBox(State);

	m_pShowBoundingBox = State;
}

void PlanetManager::showNormal(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showNormal(State);

	m_pShowNormal = State;
}

void PlanetManager::showVelocity(const bool State)
{
	for(int ii = 0; ii < m_pPlanetList.size(); ii++)
		m_pPlanetList[ii]->showVelocity(State);

	m_pShowVelocity = State;
}

void PlanetManager::loadSystem(const io::path &XmlFile, const vector3df RelativeOrigin)
{
	// TODO: Load a system and place all the objects
}
