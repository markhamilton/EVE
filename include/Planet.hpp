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
	Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, const wchar_t* Name, const f32 Radius);
	~Planet();

	// TODO: SetName
	// TODO: GetName
	// TODO: Planet Manager class?

private:
	std::wstring m_pName;
	f32 m_pRadius;
};

#endif
