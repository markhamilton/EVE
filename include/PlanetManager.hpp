#ifndef PLANETMANAGER_HPP
#define PLANETMANAGER_HPP

#include <vector>
#include <string>
#include <stdio.h>
#include "Planet.hpp"

using namespace std;
using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace io;
using namespace gui;

class PlanetManager
{
public:
	PlanetManager(IrrlichtDevice* Device);
	~PlanetManager();

	void addPlanet(const stringw Name, const double Radius, const vector3df Origin);

	void toggleWireframe() 		{ showWireframe(!m_pShowWireframe); }
	void toggleBoundingBox() 	{ showBoundingBox(!m_pShowBoundingBox); }
	void toggleNormal() 		{ showNormal(!m_pShowNormal); }
	void toggleVelocity() 		{ showVelocity(!m_pShowVelocity); }

	void showWireframe(const bool State);
	void showBoundingBox(const bool State);
	void showNormal(const bool State);
	void showVelocity(const bool State);

	void loadSystem(const io::path &XmlFile, const vector3df RelativeOrigin);

private:
	IrrlichtDevice*			m_pDevice;
	IVideoDriver*			m_pDriver;
	ISceneManager*			m_pSMgr;
	vector<Planet*>			m_pPlanetList;

	bool					m_pShowWireframe;
	bool					m_pShowBoundingBox;
	bool					m_pShowNormal;
	bool					m_pShowVelocity;
};

#endif
