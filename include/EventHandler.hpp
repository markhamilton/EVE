#include "PlanetManager.hpp"

using namespace std;

class EventHandler
{
public:

	// EventHandler(IrrlichtDevice* Device, PlanetManager* PlanetMgr);
	// bool OnEvent(const SEvent& event);
	void takeScreenShot();

private:

	// bool handleKeyPresses(const SEvent& event);

	// IrrlichtDevice* 	m_pDevice;
	PlanetManager*		m_pPlanetManager;
	int					m_pScreenShotCount;
};