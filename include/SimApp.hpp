#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <OGRE/Ogre.h>

#include <OIS/OIS.h>
#include <OIS/OISInputManager.h>

class SimApp : public OIS::KeyListener, public OIS::MouseListener
{
public:
	SimApp();
	~SimApp();
 
	bool initOgre(Ogre::String wndTitle, OIS::KeyListener *pKeyListener, OIS::MouseListener *pMouseListener);
	void createScene();
	void exit();

	void start();
	void pause();
	void resume();
	void update(double timeSinceLastFrame);
 
	// void moveCamera();
	// void buildGUI();

	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);
 
	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);

 	void onLeftPressed(const OIS::MouseEvent &evt);

	Ogre::Root*				m_pRoot;
	Ogre::RenderWindow*		m_pRenderWnd;
	Ogre::Viewport*			m_pViewport;
	Ogre::Log*				m_pLog;
	Ogre::Timer*			m_pTimer;

	OIS::InputManager*		m_pInputMgr;
	OIS::Keyboard*			m_pKeyboard;
	OIS::Mouse*				m_pMouse;

protected:
	Ogre::Camera*			m_pCamera;
	Ogre::SceneManager*		m_pSceneMgr;
    Ogre::FrameEvent    	m_FrameEvent;

private:
	void moveCamera();
	void getInput();


	Ogre::RaySceneQuery*	m_pRSQ;
	Ogre::Vector3			m_TranslateVector;
	Ogre::Real				m_MoveSpeed;
	Ogre::Degree			m_RotateSpeed;

	// Ogre::SceneNode*		m_pModelNode;
	// Ogre::Entity*		m_pModelEntity;
	// Ogre::MaterialPtr	m_pModelMat;
	// Ogre::MaterialPtr	m_pModelMatHigh;

	bool					m_bSettingsMode;
    bool 					m_bQuit;

    bool					m_bRMouseDown;
    bool					m_bLMouseDown;
};
 
#endif
