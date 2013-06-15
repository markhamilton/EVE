#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include <irrlicht.h>
#include <stdio.h>
#include <string>

class SimApp
{
public:
	SimApp();
	~SimApp();
 
	bool init(std::wstring wndTitle);
	void createScene();
	void exit();

	void start();
	void pause();
	void resume();
	void update(double timeSinceLastFrame);
 
	// void updateCamera();
	// void buildGUI();

	bool keyPressed();
	bool keyReleased();
 
	bool mouseMoved();
	bool mousePressed();
	bool mouseReleased();

 	void onLeftPressed();

	// Ogre::Root*				m_pRoot;
	// Ogre::RenderWindow*		m_pRenderWnd;
	// Ogre::Viewport*			m_pViewport;
	// Ogre::Log*				m_pLog;
	// Ogre::Timer*			m_pTimer;

	// OIS::InputManager*		m_pInputMgr;
	// OIS::Keyboard*			m_pKeyboard;
	// OIS::Mouse*				m_pMouse;

protected:
	// Ogre::Camera*			m_pCamera;
	// Ogre::SceneManager*		m_pSceneMgr;
    // Ogre::FrameEvent    	m_FrameEvent;

private:
	void updateCamera();
	void getInput();


	// Ogre::RaySceneQuery*	m_pRSQ;
	// Ogre::Vector3			m_TranslateVector;
	// Ogre::Real				m_MoveSpeed;
	// Ogre::Degree			m_RotateSpeed;

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
