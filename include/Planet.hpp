#ifndef PLANET_HPP
#define PLANET_HPP

#include <irrlicht.h>
#include <string>
#include "PlanetManager.hpp"

using namespace irr;
using namespace core;
using namespace scene;

class Planet
{
public:
	Planet();
	~Planet();

	// TODO: SetName
	// TODO: GetName
	// TODO: setWireFrame() -- Make sure to blank texture and set material flag to video::EMF_WIREFRAME
	// TODO: Planet Manager class?
	// TODO: Integrate with EVDS

private:
	// TODO: Store handle to texture
	PlanetDescriptor	m_pSelfDescriptor;
	EVDS_OBJECT			m_pEvdsObject;
};

#endif
