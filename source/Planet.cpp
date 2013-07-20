// TODO: Create Quadrilateralized spherical cube

#include "Planet.hpp"

Planet::Planet(IrrlichtDevice* Device, const stringw Name, const io::path &Texture, const f32 Radius)
{
	m_pDevice			= Device;
	m_pSMgr 			= Device->getSceneManager();
	m_pDriver 			= Device->getVideoDriver();

	m_pShowWireframe 	= false;
	m_pShowPointCloud 	= false;
	m_pShowBoundingBox 	= false;
	m_pShowNormal 		= false;
	m_pShowVelocity 	= false;

	m_pName 			= Name;

	// m_pSceneNode 	= m_pSMgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	// m_pSceneNode		= m_pSMgr->addMeshSceneNode(createPlanetMesh(Radius));
	m_pSceneNode		= m_pSMgr->addOctreeSceneNode(createPlanetMesh(Radius));

	m_pSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

	m_pSceneNode->setMaterialTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/left.png"));
}

Planet::~Planet()
{
}

SMeshBuffer* Planet::createPlanetQLSCFaceMeshBuffer(const f32 Radius, const vector3df Normal)
{
	const f32 circ 		= 2 * 3.141592 * Radius;
	const f32 range 	= circ / 4;

	const u32 polyCount = 90;
	const f32 deltaDegPerPoly = 90 / polyCount;

	vector3df rot 		= Normal.getSphericalCoordinateAngles();

	SMeshBuffer* buffer = new SMeshBuffer();
	S3DVertex vtx;
	vtx.Color.set(255, 255, 255, 255);

	// Create the vertices
	for (u32 xx = 0; xx < polyCount; ++xx)
	{
		for (u32 yy = 0; yy < polyCount; ++yy)
		{
			vector3df v = vector3df(
				(f32)xx / (f32)polyCount * Radius - Radius * 0.5,
				(f32)yy / (f32)polyCount * Radius - Radius * 0.5,
				-Radius);

			v.rotateYZBy(rot.X, vector3df(0,0,0));
			v.rotateXZBy(rot.Y, vector3df(0,0,0));
			v.rotateXYBy(rot.Z, vector3df(0,0,0));

			vtx.Pos.set(v.X, v.Y, v.Z);

			vtx.TCoords.set((f32)xx / (f32)polyCount, (f32)yy / (f32)polyCount);
			buffer->Vertices.push_back(vtx);
		}
	}

	// Create the indices
	for (u32 xx = 0; xx < polyCount - 1; ++xx)
	{
		for (u32 yy = 0; yy < polyCount - 1; ++yy)
		{
			const u32 cur = xx * polyCount + yy;

			buffer->Indices.push_back(cur);
			buffer->Indices.push_back(cur + 1);
			buffer->Indices.push_back(cur + polyCount);

			buffer->Indices.push_back(cur + 1);
			buffer->Indices.push_back(cur + 1 + polyCount);
			buffer->Indices.push_back(cur + polyCount);
		}
	}

	// Recalculate Normals
	
	buffer->recalculateBoundingBox();
	buffer->setHardwareMappingHint(EHM_STATIC);

	return buffer;
}

IMesh* Planet::createPlanetMesh(const f32 Radius)
{
	SMesh* mesh 		= new SMesh;
	SMeshBuffer* face 	= 0;

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(1, 0, 0));
	mesh->addMeshBuffer(face);
	face->drop();

	// face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 1, 0));
	// mesh->addMeshBuffer(face);
	// face->drop();

	// face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 0, 1));
	// mesh->addMeshBuffer(face);
	// face->drop();

	// face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(-1, 0, 0));
	// mesh->addMeshBuffer(face);
	// face->drop();

	// face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, -1, 0));
	// mesh->addMeshBuffer(face);
	// face->drop();

	// face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 0, -1));
	// mesh->addMeshBuffer(face);
	// face->drop();

	mesh->recalculateBoundingBox();

	return mesh;
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
	if (m_pSceneNode != 0)
	{
		m_pSceneNode->setMaterialFlag(video::EMF_WIREFRAME, State);
		if (State) showPointCloud(false);
	}

	m_pShowWireframe = State;
}

void Planet::showPointCloud(const bool State)
{
	if (m_pSceneNode != 0)
	{
		m_pSceneNode->setMaterialFlag(video::EMF_POINTCLOUD, State);
		if (State) showWireframe(false);
	}

	m_pShowPointCloud = State;
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