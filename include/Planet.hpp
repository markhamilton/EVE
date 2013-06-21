#ifndef PLANET_HPP
#define PLANET_HPP

#include <vector>
#include <irrlicht.h>
#include <string>
#include "evds.h"

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

// TODO: Make this a custom Scene Node?

class Planet //: public scene::ISceneNode
{
public:
	Planet();
	Planet(ISceneNode* parent, ISceneManager* mgr, s32 id);
	Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, const stringw Name, const io::path &Texture, const f32 Radius);
	~Planet();

	void setName(stringw Name);
	stringw getName();

	void setWireFrame(const bool State);

private:
	aabbox3d<f32> 		m_pBox;
	vector<S3DVertex>	m_pVertices;
	SMaterial			m_pMaterial;

	stringw		        m_pName;
	f32					m_pRadius;
	f32					m_pFlattening;
	f32					m_pGravity;

	// EVDS_OBJECT			m_pEvdsObject;
};

#endif
