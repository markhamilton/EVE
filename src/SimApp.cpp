// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)
// TODO: Update scene
// TODO: Update GUI
// TODO: FPS Counter
// TODO: Logging
// TODO: GUI

#include "SimApp.hpp"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
//int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main(int argc, char **argv)
#else
int main(int argc, char **argv)
#endif
{
	SimApp app;
	app.start();

	return 0;
}

SimApp::SimApp()
{
	m_pRoot 			= 0;
	m_pWindow			= 0;
	m_pSMgr				= 0;
	m_pCamera			= 0;
	m_pView				= 0;
	
	// m_pLog 				= 0;

	m_pPlanetManager 	= 0;
}

SimApp::~SimApp()
{
}

void SimApp::start()
{
	if(!init("Eve Flight Simulator")) {
		shutdown();
		return;
	}

	createScene();

	// m_pLog->log("Ready!");
	if(m_pRoot)
	{
		// Main app loop
		m_pRoot->startRendering();
	}

	shutdown();
}

void SimApp::createScene()
{
	// m_pLog->log("Creating scene...");
	// TODO: Init simulation models, physical models, lighting, shaders
	// TODO: Load scene objects here

	// Sun 
	// TODO: Initialize light source for the sun

	m_pPlanetManager = new PlanetManager(m_pRoot);
	m_pPlanetManager->addPlanet("earth", 40.0f, Vector3(0, 0, 0));

	// TODO: Set camera position
}

bool SimApp::init(const String wndTitle)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	m_pRoot = new Root("../assets/winplugins.cfg", "../assets/winconfig.cfg", "../assets/eve.log");
#elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX
	m_pRoot = new Root("../assets/linplugins.cfg", "../assets/linconfig.cfg", "../assets/eve.log");
#endif
	if(!m_pRoot->showConfigDialog())
	{
		return false;
	}
	m_pRoot->initialise(false);
	m_pRoot->addFrameListener(this);
	
	m_pWindow = m_pRoot->createRenderWindow(wndTitle, 640, 480, false);
	m_pSMgr = m_pRoot->createSceneManager(Ogre::ST_GENERIC);
	m_pCamera = m_pSMgr->createCamera("MainCam");
	m_pView = m_pWindow->addViewport(m_pCamera);

	Ogre::WindowEventUtilities::addWindowEventListener(m_pWindow, this);

	// TODO: Enable AA
	// TODO: Init logger

	return true;
}

void SimApp::shutdown()
{
	m_pRoot->shutdown();
	m_pRoot = 0;
}

// TODO: Event handler
/*
bool SimApp::OnEvent(const SEvent& event)
{
	if (!m_pDevice)
		return false;

	if(event.EventType == EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown == false)
	{
		if (event.KeyInput.Key == KEY_ESCAPE )
		{
			shutdown();
		}
		else if (event.KeyInput.Key == KEY_F1)
		{
			m_pPlanetManager->toggleWireframe();
		}
		else if (event.KeyInput.Key == KEY_F2)
		{
			m_pPlanetManager->togglePointCloud();
		}
		else if (event.KeyInput.Key == KEY_F3)
		{
			m_pPlanetManager->toggleLighting();
		}
		else if (event.KeyInput.Key == KEY_F9)
		{
			IImage* image = m_pDevice->getVideoDriver()->createScreenShot();
			if (image)
			{
				m_pDriver->writeImageToFile(image, "screenshot.png");
				image->drop();
			}
		}
	}
}
*/


void SimApp::windowClosed(Ogre::RenderWindow *rw)
{
	shutdown();
}
