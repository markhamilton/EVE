#ifndef SIMAPP_HPP
#define SIMAPP_HPP

#include "AdvancedOgreFramework.hpp"
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
