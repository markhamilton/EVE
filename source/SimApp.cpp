// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)

#include "SimApp.hpp"

#ifdef WINDOWS
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv)
#endif
{
	SimApp app;
	try	
	{
		app.start();
	}
	catch(std::exception& e)
    {
#ifdef WINDOWS
        MessageBoxA(NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        fprintf(stderr, "An exception has occurred: %s\n", e.what());
#endif
    }
 
    return 0;
}

SimApp::SimApp()
{
	m_pDevice			= 0;
	m_pDriver			= 0;
	m_pSmgr				= 0;
	m_pGui				= 0;
	m_pLog				= 0;

	m_pModelingCam		= 0;
	m_pFpsCounter		= 0;

	m_pEventHandler 	= 0;
	m_pPlanetManager	= 0;
}
 
SimApp::~SimApp()
{
	m_pLog->log("Shutting down EVE...");
}
 
void SimApp::start()
{
	init(L"Eve Flight Simulator");

	m_pLog->log("Ready!");

	int lastFPS = -1;
	while(m_pDevice->run())
	{
		m_pDriver->beginScene(true, true, SColor(255, 0, 0, 0));

		m_pSmgr->drawAll();
		m_pGui->drawAll();

		m_pDriver->endScene();

		// Update FPS Counter.
		int fps = m_pDriver->getFPS();
		if(lastFPS != fps || lastFPS == -1)
		{
			core::stringw strfps = "FPS: ";
			strfps += fps;
			m_pFpsCounter->setText(strfps.c_str());

			lastFPS = fps;
		}
	}
}
 
void SimApp::createScene()
{
	m_pLog->log("Creating scene...");
	// TODO: Init scene, camera, gui, simulation models, lighting
	// TODO: Load scene objects here
}

// bool SimApp::keyPressed(const OIS::KeyEvent &keyEventRef)
// {
// }

// bool SimApp::keyReleased(const OIS::KeyEvent &keyEventRef)
// {
// }

// bool SimApp::mouseMoved(const OIS::MouseEvent &evt)
// {
// }

// bool SimApp::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
// {
// }

// bool SimApp::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
// {
// }

// void SimApp::onLeftPressed(const OIS::MouseEvent &evt)
// {
// }

void SimApp::updateCamera()
{
}

void SimApp::getInput()
{
	if(m_bSettingsMode == false)
	{
		// if(m_pKeyboard->isKeyDown(OIS::KC_A))
		//     m_TranslateVector.x = -m_MoveScale;
 
		// if(m_pKeyboard->isKeyDown(OIS::KC_D))
		//     m_TranslateVector.x = m_MoveScale;
 
		// if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_W))
		//    m_TranslateVector.z = -m_MoveScale;
 
		//if(m_pKeyboard->isKeyDown(OIS::KC_S))
		//    m_TranslateVector.z = m_MoveScale;
 
		// if(m_pKeyboard->isKeyDown(OIS::KC_Q))
		//     m_TranslateVector.y = -m_MoveScale;
 
		// if(m_pKeyboard->isKeyDown(OIS::KC_E))
		//    m_TranslateVector.y = m_MoveScale;
 
		//camera roll
		// if(m_pKeyboard->isKeyDown(OIS::KC_Z))
		//     m_pCamera->roll(Angle(-m_MoveScale));
 
		// if(m_pKeyboard->isKeyDown(OIS::KC_X))
		//     m_pCamera->roll(Angle(m_MoveScale));
 
		//reset roll
		// if(m_pKeyboard->isKeyDown(OIS::KC_C))
		//     m_pCamera->roll(-(m_pCamera->getRealOrientation().getRoll()));
	}
}

void SimApp::update(const double timeSinceLastFrame)
{
	if(m_bQuit == true)
	{
		// TODO: Quit
		return;
	}

	// TODO: Update UI to reflect scene information

	// TODO: Update position based on speed, which is based on time
	// m_MoveScale = m_MoveSpeed   * timeSinceLastFrame;
	// m_RotScale  = m_RotateSpeed * timeSinceLastFrame;
 
	getInput();
	updateCamera();
}

// TODO: GUI
//
// void SimApp::buildGUI()
// {
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->createLabel(OgreBites::TL_TOP, "GameLbl", "Game mode", 250);
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->showCursor();
// 
// 	Ogre::StringVector items;
// 	items.push_back("cam.pX");
// 	items.push_back("cam.pY");
// 	items.push_back("cam.pZ");
// 	items.push_back("cam.oW");
// 	items.push_back("cam.oX");
// 	items.push_back("cam.oY");
// 	items.push_back("cam.oZ");
// 	items.push_back("Mode");
// 
// 	m_pDetailsPanel = OgreFramework::getSingletonPtr()->m_pTrayMgr->createParamsPanel(OgreBites::TL_TOPLEFT, "DetailsPanel", 200, items);
// 	m_pDetailsPanel->show();
// 
// 	Ogre::String infoText = "[TAB] - Switch input mode\n\n[W] - Forward / Mode up\n[S] - Backwards/ Mode down\n[A] - Left\n";
// 	infoText.append("[D] - Right\n\nPress [SHIFT] to move faster\n\n[O] - Toggle FPS / logo\n");
// 	infoText.append("[Print] - Take screenshot\n\n[ESC] - Exit");
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->createTextBox(OgreBites::TL_RIGHT, "InfoPanel", infoText, 300, 220);
// 
// 	Ogre::StringVector chatModes;
// 	chatModes.push_back("Solid mode");
// 	chatModes.push_back("Wireframe mode");
// 	chatModes.push_back("Point mode");
// 	OgreFramework::getSingletonPtr()->m_pTrayMgr->createLongSelectMenu(OgreBites::TL_TOPRIGHT, "ChatModeSelMenu", "ChatMode", 200, 3, chatModes);
// }


// TODO: Implement this render mode switching feature
// 
// void SimApp::itemSelected(OgreBites::SelectMenu* menu)
// {
//     switch(menu->getSelectionIndex())
//     {
//     case 0:
//         m_pCamera->setPolygonMode(Ogre::PM_SOLID);break;
//     case 1:
//         m_pCamera->setPolygonMode(Ogre::PM_WIREFRAME);break;
//     case 2:
//         m_pCamera->setPolygonMode(Ogre::PM_POINTS);break;
//     }
// }

void SimApp::pause()
{
	// m_pLog->logMessage("Pausing Simulator...");
}
 
void SimApp::resume()
{
	// m_pLog->logMessage("Resuming Simulator...");
}

void SimApp::exit()
{
	// m_pLog->logMessage("Leaving Simulator...");
 
	// TODO: Destroy all scene objects
}


// TODO: Create logger
// TODO: Load app settings
// TODO: Set up input listeners
bool SimApp::init(const wchar_t* wndTitle)
{

	SIrrlichtCreationParameters params = SIrrlichtCreationParameters();
	params.AntiAlias = 24;
	params.DriverType = video::EDT_OPENGL;
	params.WindowSize = core::dimension2d<u32>(800, 600);
	m_pDevice = createDeviceEx(params);
	m_pDevice->setWindowCaption(wndTitle);

	m_pPlanetManager = new PlanetManager(m_pDevice);
	m_pEventHandler = new EventHandler(m_pDevice, m_pPlanetManager);
	m_pDevice->setEventReceiver(m_pEventHandler);

	m_pDriver	= m_pDevice->getVideoDriver();
	m_pSmgr		= m_pDevice->getSceneManager();
	m_pGui 		= m_pDevice->getGUIEnvironment();
	m_pLog		= m_pDevice->getLogger();

	m_pLog->setLogLevel(ELL_DEBUG);

	// TODO: Replace skybox with a more realistic rendering 
	m_pSmgr->addSkyBoxSceneNode(
		m_pDriver->getTexture("../assets/skybox/starfield_top.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_top.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_left.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_right.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_front.jpg"),
		m_pDriver->getTexture("../assets/skybox/starfield_back.jpg"));

	m_pPlanetManager->addPlanet(L"earth", "../assets/earth.jpg", 40.0f, vector3df(0,0,0));

	m_pModelingCam = m_pSmgr->addCameraSceneNodeMaya(0, -1500.f, 200.f, 1500.f, -1, 70.f, true);
	m_pModelingCam->setTarget(vector3df(0, 0, 0));

	buildGUI();
}

void SimApp::buildGUI()
{
	// TODO: Instead of overriding colors, set theme colors to lights and pastels

	m_pFpsCounter = m_pGui->addStaticText(L"FPS:", rect<int>(10,10,200,40), false);
	m_pFpsCounter->setOverrideColor(SColor(255, 255, 255, 255));
}