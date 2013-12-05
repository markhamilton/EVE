#ifndef PLANETMANAGER_HPP
#define PLANETMANAGER_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include <OGRE/Ogre.h>
#include "Planet.hpp"

using namespace Ogre;

class PlanetManager
{
public:
	PlanetManager(Root* Device);
	~PlanetManager();

	void addPlanet(const String Name, const Real Radius, const Vector3 Origin);

	void toggleWireframe() 		{ showWireframe(!m_pShowWireframe); }
	void togglePointCloud() 	{ showPointCloud(!m_pShowPointCloud); }
	void toggleLighting() 		{ showLighting(!m_pShowLighting); }
	void toggleOutline() 		{ showOutline(!m_pShowOutline); }
	void toggleBoundingBox() 	{ showBoundingBox(!m_pShowBoundingBox); }
	void toggleNormal() 		{ showNormal(!m_pShowNormal); }
	void toggleVelocity() 		{ showVelocity(!m_pShowVelocity); }

	void showWireframe(const bool State);
	void showPointCloud(const bool State);
	void showLighting(const bool State);
	void showOutline(const bool State);
	void showBoundingBox(const bool State);
	void showNormal(const bool State);
	void showVelocity(const bool State);

	void loadSystem(const String XmlFile, const Vector3 RelativeOrigin);

private:
	Root*			m_pRoot;
	//IVideoDriver*			m_pDriver;
	//ISceneManager*			m_pSMgr;
	std::vector<Planet*>	m_pPlanetList;

	bool					m_pShowWireframe;
	bool					m_pShowPointCloud;
	bool					m_pShowLighting;
	bool					m_pShowOutline;
	bool					m_pShowBoundingBox;
	bool					m_pShowNormal;
	bool					m_pShowVelocity;
};

#endif
