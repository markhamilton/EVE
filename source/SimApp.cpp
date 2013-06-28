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
	m_pRoot				= 0;
	m_pSmgr				= 0;
	m_pWindow			= 0;
	m_pCamera			= 0;
	m_pViewport			= 0;
	m_pLog				= 0;
	m_pLMgr 			= 0;
	m_pTimer			= 0;

	// m_pFpsCounter		= 0;

	m_pInputMgr			= 0;
	m_pKeyboard			= 0;
	m_pMouse			= 0;

	m_pPlanetManager	= 0;
}
 
SimApp::~SimApp()
{
	m_pLMgr->logMessage("Shutting down EVE...");
}
 
void SimApp::start()
{
	init("Eve Flight Simulator");

	createScene();

	m_pLMgr->logMessage("Ready!");

	// TODO: Main loop
	// TODO: Update scene
	// TODO: Update GUI

	// int lastFPS = -1;
	// while(m_pDevice->run())
	// {
	// 	m_pDriver->beginScene(true, true, SColor(255, 0, 0, 0));

	// 	m_pSmgr->drawAll();
	// 	m_pGui->drawAll();

	// 	m_pDriver->endScene();

	// 	// Update FPS Counter.
	// 	int fps = m_pDriver->getFPS();
	// 	if(lastFPS != fps || lastFPS == -1)
	// 	{
	// 		core::stringw strfps = "FPS: ";
	// 		strfps += fps;
	// 		m_pFpsCounter->setText(strfps.c_str());

	// 		lastFPS = fps;
	// 	}
	// }
}
 
void SimApp::createScene()
{
	m_pLog->logMessage("Creating scene...");
	// TODO: Init scene, camera, gui, simulation models, lighting
	// TODO: Load scene objects here
	m_pPlanetManager = new PlanetManager();
	m_pPlanetManager->addPlanet("earth", /*"../assets/earth.jpg",*/ 40.0f, Ogre::Vector3(0, 0, 0));
}

bool SimApp::keyPressed(const OIS::KeyEvent &keyEventRef)
{
}

bool SimApp::keyReleased(const OIS::KeyEvent &keyEventRef)
{
}

bool SimApp::mouseMoved(const OIS::MouseEvent &evt)
{
}

bool SimApp::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
}

bool SimApp::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
}

void SimApp::onLeftPressed(const OIS::MouseEvent &evt)
{
}

void SimApp::updateCamera()
{
	// if(m_pKeyboard->isKeyDown(OIS::KC_LSHIFT)) 
	// 	m_pCamera->moveRelative(m_TranslateVector);
	// else
	// 	m_pCamera->moveRelative(m_TranslateVector / 10);
}


void SimApp::updateInput()
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
 
	updateInput();
	updateCamera();
}

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
	m_pLMgr->logMessage("Pausing Simulator...");

	// TODO: Pause simulation
}
 
void SimApp::resume()
{
	m_pLMgr->logMessage("Resuming Simulator...");

	// TODO: Resume simulation
}

void SimApp::exit()
{
	m_pLMgr->logMessage("Shutting Down Simulator...");

	m_pRoot->shutdown(); 
}

bool SimApp::init(const Ogre::String wndTitle)
{
	initLogging();
	initConfig();
	initRoot(wndTitle);
	initGUI();

	return true;
}

bool SimApp::initLogging()
{
	m_pLMgr = new Ogre::LogManager();
	m_pLog = m_pLMgr->createLog("eve.log", true, true, false);
	m_pLog->setDebugOutputEnabled(true);
	m_pLog->setLogDetail(Ogre::LL_BOREME);

	return true;
}

bool SimApp::initConfig()
{
	m_pLMgr->logMessage("Initializing Application Settings...", Ogre::LML_CRITICAL);

	// TODO: Iterate through config file
	// TODO: Use resource locations

	Ogre::ConfigFile configFile;
	configFile.load("../assets/eve.cfg");
	Ogre::ConfigFile::SectionIterator seci = configFile.getSectionIterator();

	Ogre::String sectionString = "";
	Ogre::String typeString = "";
	Ogre::String paramString = "";

	while(seci.hasMoreElements())
	{
		sectionString = seci.peekNextKey();
		Ogre::ConfigFile::SettingsMultiMap* settings = seci.getNext();

		for(Ogre::ConfigFile::SettingsMultiMap::iterator seti = settings->begin(); seti != settings->end(); ++seti )
		{
			typeString = seti->first;
			paramString = seti->second;

			m_pLMgr->logMessage("[" + sectionString + "]" + typeString + "=" + paramString);
			// TODO: pull string values in here
		}
	}

	return true;
}

bool SimApp::initRoot(Ogre::String wndTitle)
{
	m_pLMgr->logMessage("Initializing Root...", Ogre::LML_CRITICAL);

	m_pRoot = new Ogre::Root("../assets/plugins.cfg", "../assets/eve.cfg");

	// TODO: Windows support
	// m_pRoot->loadPlugin("RenderSystem_GL");

	if(!m_pRoot->showConfigDialog())
		return false;


	// Ogre::RenderSystemList *renderSystems = m_pRoot->getAvailableRenderers();

	// bool rendererFound = false;
	// for(rsi = renderSystems.begin(); rsi != renderSystems.end(); rsi++)
	// {
	// 	Ogre::RenderSystem* rs = *rsi;
	// 	Ogre::String rsName = rs->getName();

	// 	if((int)rsName.find("OpenGL") >= 0)
	// 	{
	// 		m_pRoot->setRenderSystem(*rsi);
	// 		rendererFound = true;
	// 		break;
	// 	}
	// }
	// if(!rendererFound) throw new exception();

	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("../assets", "FileSystem", "General");

	m_pWindow = m_pRoot->initialise(true, wndTitle);

	m_pSmgr = m_pRoot->createSceneManager(Ogre::ST_GENERIC, "SceneManager");
	m_pSmgr->setAmbientLight(Ogre::ColourValue(1.f, 1.f, 1.f));

	m_pCamera = m_pSmgr->createCamera("Camera");
	m_pCamera->setPosition(Ogre::Vector3(70, 0, 0));
	m_pCamera->lookAt(Ogre::Vector3(0, 0, 0));
	m_pCamera->setNearClipDistance(1);

	m_pViewport = m_pWindow->addViewport(m_pCamera);
	m_pViewport->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	m_pCamera->setAspectRatio(Ogre::Real(m_pViewport->getActualWidth()) / Ogre::Real(m_pViewport->getActualHeight()));

	m_pViewport->setCamera(m_pCamera);	

	// TODO: Set antialiasing
	// TODO: Select driver
	// TODO: 800x600 default res

	size_t hWnd = 0;
	OIS::ParamList paramList;

	m_pWindow->getCustomAttribute("WINDOW", &hWnd);

	paramList.insert(OIS::ParamList::value_type("WINDOW", Ogre::StringConverter::toString(hWnd)));

	m_pInputMgr = OIS::InputManager::createInputSystem(paramList);

	m_pKeyboard = static_cast<OIS::Keyboard*>(m_pInputMgr->createInputObject(OIS::OISKeyboard, true));
	m_pMouse = static_cast<OIS::Mouse*>(m_pInputMgr->createInputObject(OIS::OISMouse, true));

	m_pMouse->getMouseState().height = m_pWindow->getHeight();
	m_pMouse->getMouseState().width = m_pWindow->getWidth();

	m_pKeyboard->setEventCallback(this);
	m_pMouse->setEventCallback(this);

	m_pTimer = new Ogre::Timer();
	m_pTimer->reset();

	m_pWindow->setActive(true);

	return true;
}

bool SimApp::initGUI()
{
	m_pLMgr->logMessage("Initializing User Interface...", Ogre::LML_CRITICAL);

	// TODO: GUI
	// TODO: FPS counter

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
	return true;
}