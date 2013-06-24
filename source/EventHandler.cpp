#include "EventHandler.hpp"


EventHandler::EventHandler(IrrlichtDevice* Device)
{
	m_pDevice 			= Device;

	m_pScreenShotCount 	= 0; // TODO: Load this from settings
}

bool EventHandler::OnEvent(const SEvent& event)
{
	if(handleKeyPresses(event)) return true;
	return false;
}

bool EventHandler::handleKeyPresses(const SEvent& event)
{
	// check if user presses the key F9
	if (event.EventType == EET_KEY_INPUT_EVENT &&
		event.KeyInput.PressedDown)
	{
		if (event.KeyInput.Key == KEY_F9)
		{
			takeScreenShot();
			return true;
		}
	}

	return false;
}

void EventHandler::takeScreenShot()
{
	video::IImage* image = m_pDevice->getVideoDriver()->createScreenShot();
	if (image)
	{
		c8 buf[256];
		snprintf(buf, 256, "screenshots/%04d.jpg",
			++m_pScreenShotCount);
		
		c8 cmsg[320];
		snprintf(cmsg, 320, "Took snapshot %s", buf);
		m_pDevice->getLogger()->log(cmsg);

		m_pDevice->getVideoDriver()->writeImageToFile(image, buf, 85 );
		image->drop();
	}
}