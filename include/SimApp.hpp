#ifndef SIMAPP_HPP
#define SIMAPP_HPP

// #define OGRE_WCHAR_T_STRINGS 1

#include "OgreFramework.hpp"
#include "AppStateManager.hpp"
 
class SimApp 
{
public:
	SimApp();
	~SimApp();
 
	void start();
 
private:
	AppStateManager*	m_pAppStateManager;
};
 
#endif
