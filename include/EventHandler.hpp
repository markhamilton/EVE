#include <irrlicht.h>

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;

class EventHandler : public IEventReceiver
{
public:

	EventHandler(IrrlichtDevice* Device);
	bool OnEvent(const SEvent& event);
	void takeScreenShot();

private:
	
	bool handleKeyPresses(const SEvent& event);

	IrrlichtDevice* 	m_pDevice;
	int					m_pScreenShotCount;
};