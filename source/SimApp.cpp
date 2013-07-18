// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)
// TODO: Update scene
// TODO: Update GUI
// TODO: FPS Counter
// TODO: Logging
// TODO: GUI

#include "SimApp.hpp"
#include "EventHandler.hpp"

int main(int argc, char **argv)
{
	SimApp app;
	app.start();

	return 0;
}

SimApp::SimApp()
{
	m_pDevice 			= 0;
	m_pDriver			= 0;
	m_pSMgr				= 0;
	m_pCamera			= 0;

	m_pPlanetManager 	= 0;
}

SimApp::~SimApp()
{
}

void SimApp::start()
{
	init(L"Eve Flight Simulator");

	createScene();

	// Main app loop
	while(m_pDevice->run())
	{
		m_pDriver->beginScene(true, true, video::SColor(255, 127, 0, 255));

		m_pSMgr->drawAll();
		m_pDriver->endScene();
	}
}

void SimApp::createScene()
{
	//m_pLog->logMessage("Creating scene...");
	// TODO: Init scene, camera, gui, simulation models, lighting
	// TODO: Load scene objects here

	// Skybox is temporary, I will add something more realistic later
	ISceneNode *skybox = m_pSMgr->addSkyBoxSceneNode(
		m_pDriver->getTexture("../assets/skybox/starfield_top.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_top.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_left.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_right.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_front.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_back.jpg"));


	m_pPlanetManager = new PlanetManager(m_pDevice);
	m_pPlanetManager->addPlanet("earth", 40.0f, vector3df(0, 0, 0));

	m_pCamera = m_pSMgr->addCameraSceneNodeMaya(0, -1500, 200, 1500, -1, 70, true);
	m_pCamera->setPosition(vector3df(70, 0, 0));
	m_pCamera->setTarget(vector3df(0, 0, 0));
}

bool SimApp::init(const stringw wndTitle)
{
	SIrrlichtCreationParameters wndParam;
	wndParam.AntiAlias 				= 32;
	wndParam.Bits 					= 32;
	wndParam.DriverType 			= EDT_OPENGL;
	wndParam.Doublebuffer 			= true;
	wndParam.DriverMultithreaded	= true;
	// wndParam.EventReceiver 			= EventHandler();
	wndParam.Fullscreen 			= false;
	wndParam.HighPrecisionFPU		= true;
	wndParam.Stencilbuffer			= true;
	wndParam.Vsync					= false;
	wndParam.WindowSize				= dimension2d<u32>(640, 480);
	wndParam.WithAlphaChannel		= false;
	wndParam.ZBufferBits			= 16;

	m_pDevice = createDeviceEx(wndParam);
	m_pDevice->setWindowCaption(wndTitle.c_str());

	m_pDriver = m_pDevice->getVideoDriver();
	m_pSMgr = m_pDevice->getSceneManager();


	return true;
}
