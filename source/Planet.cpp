// TODO: Create Quadrilateralized spherical cube

#include "Planet.hpp"

// Planet::Planet()
// {
// 	m_pSceneNode 		= 0;

// 	m_pShowWireframe 	= false;
// 	m_pShowBoundingBox 	= false;
// 	m_pShowNormal 		= false;
// 	m_pShowVelocity 	= false;
// }

IMesh* Planet::createPlanetQLSCFaceMesh(const f32 radius, const vector3df normal) const
{
	const f32 circ 		= 2 * 3.141592 * radius;
	const f32 range 	= circ / 4;

	const u32 polyCount = 90;


	SMeshBuffer* buffer = new SMeshBuffer();

	// buffer->setHardwareMappingHint(EHM_STATIC);

	S3DVertex vtx;
	vtx.Color.set(255, 255, 255, 255);

	// Create the vertices
	buffer->Vertices.reallocate(polyCount * polyCount);
	for (u32 yy = 0; yy < polyCount - 1; ++yy)
	{
		for (u32 xx = 0; xx < polyCount - 1; ++xx)
		{
			vtx.Pos.set(xx, 0, yy);
			buffer->Vertices.push_back(vtx);
		}
	}

	// Create the indices
	buffer->Indices.reallocate(polyCount * polyCount * 6);

}

Planet::Planet(IrrlichtDevice* Device, const stringw Name, const io::path &Texture, const f32 Radius)
{
	m_pDevice = Device;
	m_pSMgr = Device->getSceneManager();
	m_pDriver = Device->getVideoDriver();

	m_pName = Name;

	m_pSceneNode = m_pSMgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	// m_pSceneNode = m_pSMgr->addCubeSceneNode(Radius, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	m_pSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

	m_pSceneNode->setMaterialTexture(0, m_pDriver->getTexture(Texture));
}

Planet::~Planet()
{
}

// virtual void Planet::OnRegisterSceneNode()
// {
// 	if (IsVisible)
// 		m_pSMgr->registerNodeForRendering(this);

// 	ISceneNode::OnRegisterSceneNode();
// }

// virtual void Planet::render()
// {
// 	u16 indices[] = {   0,2,3, 2,1,3, 1,0,3, 2,0,1  };
// 	video::IVideoDriver* driver = SceneManager->getVideoDriver();

// 	driver->setMaterial(m_pMaterial);
// 	driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
// 	driver->drawVertexPrimitiveList(&Vertices[0], 4, &indices[0], 4, video::EVT_STANDARD, scene::EPT_TRIANGLES, video::EIT_16BIT);
// }

// virtual const core::aabbox3d<f32>& Planet::getBoundingBox() const
// {
// 	return Box;
// }

// virtual u32 Planet::getMaterialCount() const
// {
// 	return 1;
// }

// virtual video::SMaterial& Planet::getMaterial(u32 i)
// {
// 	return Material;
// }

void Planet::setName(stringw Name)
{
	m_pName = Name;
}
stringw Planet::getName()
{
	return m_pName;
}

void Planet::showWireframe(const bool State)
{
	if(m_pSceneNode != 0)
		m_pSceneNode->setMaterialFlag(video::EMF_WIREFRAME, State);

	m_pShowWireframe = State;
}

void Planet::showBoundingBox(const bool State)
{
	// TODO: Show/hide bounding box
	m_pShowBoundingBox = State;
}

void Planet::showNormal(const bool State)
{
	// TODO: Show/hide normals
	m_pShowNormal = State;
}

void Planet::showVelocity(const bool State)
{
	// TODO: Show/hide velocity markers
	m_pShowVelocity = State;
}