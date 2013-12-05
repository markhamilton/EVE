#ifndef PLANET_HPP
#define PLANET_HPP

#include <vector>
#include <OGRE/Ogre.h>
#include "evds.h"

using namespace std;
using namespace Ogre;

class Planet
{
public:
	Planet(Root* root, const String Name, const String Texture, const Real Radius);
	~Planet();

	void setName(const String Name);
	String getName();

	// Misc visualization parameters
	void showWireframe(const bool State);
	void showPointCloud(const bool State);
	void showLighting(const bool State);
	void showOutline(const bool State);
	void showBoundingBox(const bool State);
	void showNormal(const bool State);
	void showVelocity(const bool State);

private:
	// SMeshBuffer* createPlanetQLSCFaceMeshBuffer(const Real Radius, const Vector3 Direction);
	// SMesh* createPlanetMesh(const Real Radius);

	Root*					m_pRoot;
	//ISceneManager*			m_pSMgr;
	//IVideoDriver*				m_pDriver;

	//IMeshSceneNode*			m_pSceneNode;
	//SMaterial					m_pMaterial;

	//aabbox3d<f32> 			m_pBox;
	// vector<S3DVertex>		m_pVertices;

	String	        		m_pName;
	Real 					m_RotateSpeed;
	Real					m_pRadius;
	Real 					m_pFlattening;
	Real					m_pGravity;

	Vector3 				m_pOrigin;

	int						m_pShowWireframe;
	int						m_pShowPointCloud;
	int						m_pShowLighting;
	int						m_pShowOutline;
	bool					m_pShowBoundingBox;
	bool					m_pShowNormal;
	bool					m_pShowVelocity;

	// EVDS_OBJECT			m_pEvdsObject;
};

#endif
