//|||||||||||||||||||||||||||||||||||||||||||||||
 
#ifndef OGRE_FRAMEWORK_HPP
#define OGRE_FRAMEWORK_HPP
 
//|||||||||||||||||||||||||||||||||||||||||||||||
 
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreEntity.h>
#include <OGRE/OgreLogManager.h>
#include <OGRE/OgreOverlay.h>
#include <OGRE/OgreOverlayElement.h>
#include <OGRE/OgreOverlayManager.h>
#include <OGRE/OgreRoot.h>
#include <OGRE/OgreViewport.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreRenderWindow.h>
#include <OGRE/OgreConfigFile.h>
 
#include <OIS/OISEvents.h>
#include <OIS/OISInputManager.h>
#include <OIS/OISKeyboard.h>
#include <OIS/OISMouse.h>
 
// #include <OGRE/SdkTrays.h>
 
//|||||||||||||||||||||||||||||||||||||||||||||||
 
class OgreFramework : public Ogre::Singleton<OgreFramework>, OIS::KeyListener, OIS::MouseListener
{
public:
	OgreFramework();
	~OgreFramework();
 
	bool initOgre(Ogre::String wndTitle, OIS::KeyListener *pKeyListener = 0, OIS::MouseListener *pMouseListener = 0);
	void updateOgre(double timeSinceLastFrame);
 
	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);
 
	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
 
	Ogre::Root*				m_pRoot;
	Ogre::RenderWindow*		m_pRenderWnd;
	Ogre::Viewport*			m_pViewport;
	Ogre::Log*				m_pLog;
	Ogre::Timer*			m_pTimer;
 
	OIS::InputManager*		m_pInputMgr;
	OIS::Keyboard*			m_pKeyboard;
	OIS::Mouse*				m_pMouse;
 
    OgreBites::SdkTrayManager* m_pTrayMgr;
 
private:
	OgreFramework(const OgreFramework&);
	OgreFramework& operator= (const OgreFramework&);
};
 
//|||||||||||||||||||||||||||||||||||||||||||||||
 
#endif
 
//|||||||||||||||||||||||||||||||||||||||||||||||
