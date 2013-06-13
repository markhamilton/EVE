#include "SimApp.hpp"
 
SimApp::SimApp()
{
	// TODO: Make sure all of our scene objects are initialized to null
    m_pRoot             = 0;
    m_pRenderWnd        = 0;
    m_pViewport         = 0;
    m_pLog              = 0;
    m_pTimer			= 0;
 
    m_pInputMgr			= 0;
    m_pKeyboard			= 0;
    m_pMouse			= 0;

    m_FrameEvent        = Ogre::FrameEvent();


	// m_MoveSpeed			= 0.1f;
	// m_RotateSpeed		= 0.3f;

	// App states
	m_bSettingsMode		= false;
	m_bQuit             = false;

	m_bLMouseDown		= false;
	m_bRMouseDown		= false;
}
 
SimApp::~SimApp()
{
	m_pLog->logMessage("Shutting down EVE...");
	if(m_pInputMgr)	OIS::InputManager::destroyInputSystem(m_pInputMgr);
    if(m_pRoot) 	delete m_pRoot;
}
 
void SimApp::start()
{
	if(!initOgre("EVE Flight Simulator", 0, 0))
		return;
 
	m_pLog->logMessage("Simulator initialized!");
}
 
void SimApp::createScene()
{
    // ENTERING THE SCENE HERE
    m_pLog->logMessage("Entering scene...");
 
    m_pRoot->createSceneManager(ST_GENERIC, "EveSceneMgr");
    m_pSceneMgr->setAmbientLight(Ogre::ColourValue(0.7f, 0.7f, 0.7f));
 
    m_pRSQ = m_pSceneMgr->createRayQuery(Ray());
    m_pRSQ->setQueryMask(OGRE_HEAD_MASK);
 
    m_pCamera = m_pSceneMgr->createCamera("OverviewCamera");
    m_pCamera->setPosition(Vector3(5, 60, 60));
    m_pCamera->lookAt(Vector3(5, 20, 0));
    m_pCamera->setNearClipDistance(5);
 
    m_pCamera->setAspectRatio(Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualWidth()) /
        Real(OgreFramework::getSingletonPtr()->m_pViewport->getActualHeight()));
 
    OgreFramework::getSingletonPtr()->m_pViewport->setCamera(m_pCamera);
    m_pCurrentObject = 0;
 
    // buildGUI();

    // CREATING THE SCENE HERE

    m_pSceneMgr->createLight("Light")->setPosition(75,75,75);
 
	// TODO: Load scene objects here
 
    // m_pSceneMgr->getEntity("Cube01")->setQueryFlags(CUBE_MASK);
    // m_pSceneMgr->getEntity("Cube02")->setQueryFlags(CUBE_MASK);
    // m_pSceneMgr->getEntity("Cube03")->setQueryFlags(CUBE_MASK);
 
    // m_pOgreHeadEntity = m_pSceneMgr->createEntity("Cube", "ogrehead.mesh");
    // m_pOgreHeadEntity->setQueryFlags(OGRE_HEAD_MASK);
    // m_pOgreHeadNode = m_pSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode");
    // m_pOgreHeadNode->attachObject(m_pOgreHeadEntity);
    // m_pOgreHeadNode->setPosition(Vector3(0, 0, -25));
 
    // m_pOgreHeadMat = m_pOgreHeadEntity->getSubEntity(1)->getMaterial();
    // m_pOgreHeadMatHigh = m_pOgreHeadMat->clone("OgreHeadMatHigh");
    // m_pOgreHeadMatHigh->getTechnique(0)->getPass(0)->setAmbient(1, 0, 0);
    // m_pOgreHeadMatHigh->getTechnique(0)->getPass(0)->setDiffuse(1, 0, 0, 0);

}

bool SimApp::keyPressed(const OIS::KeyEvent &keyEventRef)
{
    if(m_bSettingsMode == true)
    {
    	// TODO: Handle menu commands
    }
 
    if(m_pKeyboard->isKeyDown(OIS::KC_ESCAPE))
    {
        m_bSettingsMode = !m_bSettingsMode;
        return true;
    }

    if(m_pKeyboard->isKeyDown(OIS::KC_SYSRQ))
    {
        m_pRenderWnd->writeContentsToTimestampedFile("EVE_Screenshot_", ".jpg");
        return true;
    }

 
    return true;
}

bool SimApp::keyReleased(const OIS::KeyEvent &keyEventRef)
{
    keyPressed(keyEventRef);
    return true;
}

bool SimApp::mouseMoved(const OIS::MouseEvent &evt)
{
    if(m_bRMouseDown)
    {
        m_pCamera->yaw(Degree(evt.state.X.rel * -0.1f));
        m_pCamera->pitch(Degree(evt.state.Y.rel * -0.1f));
    }
 
    return true;
}

bool SimApp::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(id == OIS::MB_Left)
    {
        onLeftPressed(evt);
        m_bLMouseDown = true;
    }
    else if(id == OIS::MB_Right)
        m_bRMouseDown = true;
 
    return true;
}

bool SimApp::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id)
{
    if(id == OIS::MB_Left)
        m_bLMouseDown = false;
    else if(id == OIS::MB_Right)
        m_bRMouseDown = false;
 
    return true;
}

void SimApp::onLeftPressed(const OIS::MouseEvent &evt)
{
    if(m_pCurrentObject)
    {
        m_pCurrentObject->showBoundingBox(false);
        m_pCurrentEntity->getSubEntity(1)->setMaterial(m_pOgreHeadMat);
    }
 
    Ogre::Ray mouseRay = m_pCamera->getCameraToViewportRay(OgreFramework::getSingletonPtr()->m_pMouse->getMouseState().X.abs / float(evt.state.width),
        OgreFramework::getSingletonPtr()->m_pMouse->getMouseState().Y.abs / float(evt.state.height));
    m_pRSQ->setRay(mouseRay);
    m_pRSQ->setSortByDistance(true);
 
    Ogre::RaySceneQueryResult &result = m_pRSQ->execute();
    Ogre::RaySceneQueryResult::iterator itr;
 
    for(itr = result.begin(); itr != result.end(); itr++)
    {
        if(itr->movable)
        {
            m_pLog->logMessage("MovableName: " + itr->movable->getName());
            m_pCurrentObject = m_pSceneMgr->getEntity(itr->movable->getName())->getParentSceneNode();
            m_pLog->logMessage("ObjName " + m_pCurrentObject->getName());
            m_pCurrentObject->showBoundingBox(true);
            m_pCurrentEntity = m_pSceneMgr->getEntity(itr->movable->getName());
            m_pCurrentEntity->getSubEntity(1)->setMaterial(m_pOgreHeadMatHigh);
            break;
        }
    }
}

void SimApp::moveCamera()
{
    if(m_pKeyboard->isKeyDown(OIS::KC_LSHIFT))
        m_pCamera->moveRelative(m_TranslateVector);
    m_pCamera->moveRelative(m_TranslateVector / 10);
}

void SimApp::getInput()
{
    if(m_bSettingsMode == false)
    {
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_A))
            m_TranslateVector.x = -m_MoveScale;
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_D))
            m_TranslateVector.x = m_MoveScale;
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_W))
            m_TranslateVector.z = -m_MoveScale;
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_S))
            m_TranslateVector.z = m_MoveScale;
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_Q))
            m_TranslateVector.y = -m_MoveScale;
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_E))
            m_TranslateVector.y = m_MoveScale;
 
        //camera roll
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_Z))
            m_pCamera->roll(Angle(-m_MoveScale));
 
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_X))
            m_pCamera->roll(Angle(m_MoveScale));
 
        //reset roll
        if(OgreFramework::getSingletonPtr()->m_pKeyboard->isKeyDown(OIS::KC_C))
            m_pCamera->roll(-(m_pCamera->getRealOrientation().getRoll()));
    }
}

void SimApp::update(double timeSinceLastFrame)
{
    m_FrameEvent.timeSinceLastFrame = timeSinceLastFrame;


    if(m_bQuit == true)
    {
    	// TODO: Quit
        return;
    }

    // TODO: Update UI to reflect scene information
    // OgreFramework::getSingletonPtr()->m_pTrayMgr->frameRenderingQueued(m_FrameEvent);
    // if(!OgreFramework::getSingletonPtr()->m_pTrayMgr->isDialogVisible())
    // {
    //     if(m_pDetailsPanel->isVisible())
    //     {
    //         m_pDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(m_pCamera->getDerivedPosition().x));
    //         m_pDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(m_pCamera->getDerivedPosition().y));
    //         m_pDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(m_pCamera->getDerivedPosition().z));
    //         m_pDetailsPanel->setParamValue(3, Ogre::StringConverter::toString(m_pCamera->getDerivedOrientation().w));
    //         m_pDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(m_pCamera->getDerivedOrientation().x));
    //         m_pDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(m_pCamera->getDerivedOrientation().y));
    //         m_pDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(m_pCamera->getDerivedOrientation().z));
    //         if(m_bSettingsMode)
    //             m_pDetailsPanel->setParamValue(7, "Buffered Input");
    //         else
    //             m_pDetailsPanel->setParamValue(7, "Un-Buffered Input");
    //     }
    // }
 
    m_MoveScale = m_MoveSpeed   * timeSinceLastFrame;
    m_RotScale  = m_RotateSpeed * timeSinceLastFrame;
 
    m_TranslateVector = Vector3::ZERO;
 
    getInput();
    moveCamera();
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

bool SimApp::pause()
{
    m_pLog->logMessage("Pausing Simulator...");
 
    return true;
}
 
void SimApp::resume()
{
    m_pLog->logMessage("Resuming Simulator...");
 
	m_pViewport->setCamera(m_pCamera);
    m_bQuit = false;
}

void SimApp::exit()
{
    m_pLog->logMessage("Leaving Simulator...");
 
    m_pSceneMgr->destroyCamera(m_pCamera);
    m_pSceneMgr->destroyQuery(m_pRSQ);
    if(m_pSceneMgr)
        m_pRoot->destroySceneManager(m_pSceneMgr);
}


bool SimApp::initOgre(Ogre::String wndTitle, OIS::KeyListener *pKeyListener, OIS::MouseListener *pMouseListener)
{
    m_pLog = Ogre::LogManager::getSingleton().createLog("eve-sim.log", true, true, false);
    m_pLog->setDebugOutputEnabled(true);
 
    m_pRoot = new Ogre::Root();
 
    if(!m_pRoot->showConfigDialog())
        return false;
    m_pRenderWnd = m_pRoot->initialise(true, wndTitle);
 
    m_pViewport = m_pRenderWnd->addViewport(0);
    m_pViewport->setBackgroundColour(ColourValue(0.5f, 0.5f, 0.5f, 1.0f));
 
    m_pViewport->setCamera(0);
 
    size_t hWnd = 0;
    OIS::ParamList paramList;
    m_pRenderWnd->getCustomAttribute("WINDOW", &hWnd);
 
    paramList.insert(OIS::ParamList::value_type("WINDOW", Ogre::StringConverter::toString(hWnd)));
 
    m_pInputMgr = OIS::InputManager::createInputSystem(paramList);
 
    m_pKeyboard = static_cast<OIS::Keyboard*>(m_pInputMgr->createInputObject(OIS::OISKeyboard, true));
    m_pMouse = static_cast<OIS::Mouse*>(m_pInputMgr->createInputObject(OIS::OISMouse, true));
 
    m_pMouse->getMouseState().height = m_pRenderWnd->getHeight();
    m_pMouse->getMouseState().width  = m_pRenderWnd->getWidth();
 
    if(pKeyListener == 0)
        m_pKeyboard->setEventCallback(this);
    else
        m_pKeyboard->setEventCallback(pKeyListener);
 
    if(pMouseListener == 0)
        m_pMouse->setEventCallback(this);
    else
        m_pMouse->setEventCallback(pMouseListener);
 
    Ogre::String secName, typeName, archName;
    Ogre::ConfigFile cf;
    cf.load("resources.cfg");
 
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;
            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(archName, typeName, secName);
        }
    }
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
    Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
 
    m_pTimer = new Ogre::Timer();
    m_pTimer->reset();
 
    m_pRenderWnd->setActive(true);
 
    return true;
}