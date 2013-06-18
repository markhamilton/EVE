#include "Planet.hpp"


Planet::Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, const wchar_t* Name, const f32 Radius)
{
	// TODO: Get singleton for the driver and scenemanager instead of passing states
	// TODO: Create Quadrilateralized spherical cube
	// TODO: Determine appropriate poly count from relative size
	m_pName = Name;

	IMeshSceneNode* planet = Smgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	planet->setMaterialFlag(video::EMF_LIGHTING, false);
	planet->setMaterialTexture(0, Driver->getTexture("../assets/earth.jpg"));
}