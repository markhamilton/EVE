#include "PlanetManager.hpp"

PlanetManager::PlanetManager(Root* root)
{
	m_pRoot				= root;
	//m_pDriver 			= Device->getVideoDriver();
	//m_pSMgr 			= Device->getSceneManager();

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

void PlanetManager::addPlanet(const String Name, const Real Radius, const Vector3 Origin)
{
	Planet* p = new Planet(m_pRoot, Name, "../assets/earth.jpg", Radius);
	m_pPlanetList.push_back(p);
}

void PlanetManager::showWireframe(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showWireframe(State);

	// Disable point cloud flags
	if (State) showPointCloud(false);

	m_pShowWireframe = State;
}

void PlanetManager::showPointCloud(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showPointCloud(State);

	// Disable wireframe flags
	if (State) showWireframe(false);

	m_pShowPointCloud = State;
}

void PlanetManager::showLighting(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showLighting(State);

	m_pShowLighting = State;
}

void PlanetManager::showOutline(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showOutline(State);

	m_pShowOutline = State;
}

void PlanetManager::showBoundingBox(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showBoundingBox(State);

	m_pShowBoundingBox = State;
}

void PlanetManager::showNormal(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showNormal(State);

	m_pShowNormal = State;
}

void PlanetManager::showVelocity(const bool State)
{
	for(std::vector<Planet *>::iterator it = m_pPlanetList.begin(); it != m_pPlanetList.end(); ++it)
		(*it)->showVelocity(State);

	m_pShowVelocity = State;
}

void PlanetManager::loadSystem(const String XmlFile, const Vector3 RelativeOrigin)
{
	// TODO: Load a system and place all the objects
}
