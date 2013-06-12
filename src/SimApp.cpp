#include "SimApp.hpp"
 
#include "MenuState.hpp"
#include "GameState.hpp"
#include "PauseState.hpp"
 
SimApp::SimApp()
{
	m_pAppStateManager = 0;
}
 
SimApp::~SimApp()
{
	delete m_pAppStateManager;
        delete OgreFramework::getSingletonPtr();
}
 
void SimApp::start()
{
	new OgreFramework();
	if(!OgreFramework::getSingletonPtr()->initOgre("AdvancedOgreFramework", 0, 0))
		return;
 
	OgreFramework::getSingletonPtr()->m_pLog->logMessage("Simulator initialized!");
 
	m_pAppStateManager = new AppStateManager();
 
	MenuState::create(m_pAppStateManager, "MenuState");
	GameState::create(m_pAppStateManager, "GameState");
        PauseState::create(m_pAppStateManager, "PauseState");
 
	m_pAppStateManager->start(m_pAppStateManager->findByName("MenuState"));
}
 
