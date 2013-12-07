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
//#else
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
	init("Eve Flight Simulator");

	createScene();

	// m_pLog->log("Ready!");

	// Main app loop
	m_pRoot->startRendering();

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
	m_pRoot = new Root();
	if(!m_pRoot->showConfigDialog())
	{
		return false;
	}
	m_pRoot->initialise(false);
	
	m_pWindow = m_pRoot->createRenderWindow(wndTitle, 640, 480, false);
	m_pSMgr = m_pRoot->createSceneManager(Ogre::ST_GENERIC);
	m_pCamera = m_pSMgr->createCamera("MainCam");
	m_pView = m_pWindow->addViewport(m_pCamera);

	// TODO: Enable AA
	// TODO: Init logger

	return true;
}

void SimApp::shutdown()
{
	m_pRoot->shutdown();
	delete m_pRoot;
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
