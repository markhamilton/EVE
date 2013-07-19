// TODO: Make this a custom Scene Node?

#ifndef PLANET_HPP
#define PLANET_HPP

#include <irrlicht.h>
#include <vector>
#include "evds.h"

using namespace irr;
using namespace core;
using namespace video;
using namespace scene;
using namespace io;
using namespace gui;

class Planet
{
public:
	Planet();
	Planet(IrrlichtDevice* Device, const stringw Name, const io::path &Texture, const f32 Radius);
	~Planet();

	void setName(stringw Name);
	stringw getName();

	// Misc visualization parameters
	void showWireframe(const bool State);
	void showBoundingBox(const bool State);
	void showNormal(const bool State);
	void showVelocity(const bool State);

private:
	IMesh* createPlanetQLSCFaceMesh(const f32 radius, const vector3df normal) const;
	// IMesh* createPlanetMesh(const s32 Radius);

	IrrlichtDevice*			m_pDevice;
	ISceneManager*			m_pSMgr;
	IVideoDriver*			m_pDriver;

	IMeshSceneNode*			m_pSceneNode;
	SMaterial				m_pMaterial;

	aabbox3d<f32> 			m_pBox;
	// vector<S3DVertex>		m_pVertices;

	stringw	        		m_pName;
	f32						m_RotateSpeed;
	f32						m_pRadius;
	f32						m_pFlattening;
	f32						m_pGravity;

	vector3df				m_pOrigin;

	bool					m_pShowWireframe;
	bool					m_pShowBoundingBox;
	bool					m_pShowNormal;
	bool					m_pShowVelocity;

	// EVDS_OBJECT			m_pEvdsObject;
};

#endif
