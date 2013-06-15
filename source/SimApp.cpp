#include "SimApp.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

SimApp::SimApp()
{
}
 
SimApp::~SimApp()
{
	// m_pLog->logMessage("Shutting down EVE...");
}
 
void SimApp::start()
{
	IrrlichtDevice *device = createDevice(EDT_SOFTWARE, dimension2d<u32>(512, 384), 16, false, false, false, 0);
	
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	guienv->addStaticText(L"EVE Flight Simulator",
		rect<int>(10,10,200,22), true);

	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	// io::IFileSystem *irrFile;
	// ITimer *irrTimer;
	// ILogger *irrLog;
	// if(!initOgre("EVE Flight Simulator", 0, 0))
	// m_pLog->logMessage("Simulator initialized!");
}
 
void SimApp::createScene()
{
	// m_pLog->logMessage("Entering scene...");
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

void SimApp::update(double timeSinceLastFrame)
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


bool SimApp::init(std::wstring wndTitle)
{
	// TODO: Create logger
	// TODO: Load app settings
	// TODO: Init irrlicht
	// TODO: Show init dialog
	// TODO: Create main viewport, window
	// TODO: Create camera if global camera is used (?)
	// TODO: Init input managers 
	// TODO: Set up input listeners
}
