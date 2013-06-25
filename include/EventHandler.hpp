#include <irrlicht.h>
#include "PlanetManager.hpp"

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;

class EventHandler : public IEventReceiver
{
public:

	EventHandler(IrrlichtDevice* Device, PlanetManager* PlanetMgr);
	bool OnEvent(const SEvent& event);
	void takeScreenShot();

private:

	bool handleKeyPresses(const SEvent& event);

	IrrlichtDevice* 	m_pDevice;
	PlanetManager*		m_pPlanetManager;
	int					m_pScreenShotCount;
};