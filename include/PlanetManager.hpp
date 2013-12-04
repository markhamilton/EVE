#ifndef PLANETMANAGER_HPP
#define PLANETMANAGER_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include "Planet.hpp"

using namespace std;

class PlanetManager
{
public:
	PlanetManager(Root* Device);
	~PlanetManager();

	void addPlanet(const stringw Name, const double Radius, const vector3df Origin);

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

	void loadSystem(const stringw XmlFile, const Vector3 RelativeOrigin);

private:
	//IrrlichtDevice*			m_pDevice;
	//IVideoDriver*			m_pDriver;
	//ISceneManager*			m_pSMgr;
	vector<Planet*>			m_pPlanetList;

	bool					m_pShowWireframe;
	bool					m_pShowPointCloud;
	bool					m_pShowLighting;
	bool					m_pShowOutline;
	bool					m_pShowBoundingBox;
	bool					m_pShowNormal;
	bool					m_pShowVelocity;
};

#endif
