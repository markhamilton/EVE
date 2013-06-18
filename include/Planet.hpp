#ifndef PLANET_HPP
#define PLANET_HPP

#include <irrlicht.h>
#include <string>

using namespace irr;
using namespace core;
using namespace scene;

class Planet
{
public:
	Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, const wchar_t* Name, const io::path &Texture, const f32 Radius);
	~Planet();

	// TODO: SetName
	// TODO: GetName
	// TODO: setWireFrame() -- Make sure to blank texture and set material flag to video::EMF_WIREFRAME
	// TODO: Planet Manager class?
	// TODO: Integrate with EVDS

private:
	// TODO: Store handle to texture
	std::wstring m_pName;
	f32 m_pRadius;
};

#endif
