#ifndef PLANET_HPP
#define PLANET_HPP

#include <vector>
#include <irrlicht.h>
#include <string>
#include "evds.h"
#include "PlanetManager.hpp"

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;


class Planet //: public scene::ISceneNode
{
public:
	Planet();
	Planet(ISceneNode* parent, ISceneManager* mgr, s32 id);
	Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, wchar_t* Name, const io::path &Texture, const f32 Radius);
	~Planet();

	void setName(wchar_t* Name);
	wchar_t* getName();

	void setWireFrame(const bool State);

private:
	aabbox3d<f32> 		Box;
	vector<S3DVertex>	Vertices;
	SMaterial			Material;

	wchar_t*			m_pName;
	f32					m_pRadius;
	f32					m_pFlattening;
	f32					m_pGravity;

	// EVDS_OBJECT			m_pEvdsObject;
};

#endif
