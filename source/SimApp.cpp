// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)
// TODO: Update scene
// TODO: Update GUI
// TODO: FPS Counter
// TODO: Logging
// TODO: GUI

#include "SimApp.hpp"

int main(int argc, char **argv)
{
	SimApp app;
	app.start();

	return 0;
}

SimApp::SimApp()
{
	m_pDevice 			= 0;
	m_pVideo			= 0;
	m_pSMgr				= 0;

	m_pPlanetManager 	= 0;
}

SimApp::~SimApp()
{
}

void SimApp::start()
{
	m_pDevice = createDevice(EDT_OPENGL, core::dimension2d<u32>(640, 480));

	m_pVideo = m_pDevice->getVideoDriver();
	m_pSMgr = m_pDevice->getSceneManager();

	while(m_pDevice->run())
	{
		m_pVideo->beginScene(true, true, video::SColor(255, 127, 0, 255));

		m_pSMgr->drawAll();
		m_pVideo->endScene();
	}
}

void SimApp::createScene()
{
	//m_pLog->logMessage("Creating scene...");
	// TODO: Init scene, camera, gui, simulation models, lighting
	// TODO: Load scene objects here
	m_pPlanetManager = new PlanetManager();
	// m_pPlanetManager->addPlanet("earth", 40.0f, Vector3f(0, 0, 0));
}

void SimApp::renderScene()
{

}

bool SimApp::init(const stringw wndTitle)
{
	return true;
}
