// TODO: Create Quadrilateralized spherical cube

#include "Planet.hpp"

Planet::Planet(Root* root, const stringw Name, const stringw Texture, const double Radius)
{
	m_pRoot				= root;
//	m_pSMgr 			= Device->getSceneManager();
//	m_pDriver 			= Device->getVideoDriver();

	m_pShowWireframe 	= false;
	m_pShowPointCloud 	= false;
	m_pShowLighting 	= true;
	m_pShowOutline 		= false;
	m_pShowBoundingBox 	= false;
	m_pShowNormal 		= false;
	m_pShowVelocity 	= false;

	m_pName 			= Name;

	// IMeshSceneNode* ref	= m_pSMgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	// ref->setMaterialFlag(video::EMF_LIGHTING, false);
	// ref->setMaterialTexture(0, m_pDriver->getTexture("../assets/earth.jpg"));

//	m_pSceneNode		= m_pSMgr->addOctreeSceneNode(createPlanetMesh(Radius));
	// m_pSceneNode		= m_pSMgr->addMeshSceneNode(createPlanetMesh(Radius));

//	m_pSceneNode->setMaterialFlag(video::EMF_LIGHTING, true);
}

Planet::~Planet()
{
}

SMeshBuffer* Planet::createPlanetQLSCFaceMeshBuffer(const Real Radius, const Vector3 Direction)
{
	const Real circ 		= 2 * 3.141592 * Radius;
	const Real range 		= circ / 4;

	const int polyCount = 40;
	//const Vector3 rot = Direction.getHorizontalAngle();

	//SMeshBuffer* buffer = new SMeshBuffer();
	//S3DVertex vtx;
	//vtx.Color.set(255, 255, 255, 255);

	// Create the vertices
	for (int xx = 0; xx < polyCount; ++xx)
	{
		for (int yy = 0; yy < polyCount; ++yy)
		{
			// // Makes a cube
			// vector3df v = vector3df(
			// 	(f32)xx / ((f32)polyCount - 1.0) * Radius * 2 - Radius,
			// 	(f32)yy / ((f32)polyCount - 1.0) * Radius * 2 - Radius,
			// 	-Radius);

			// v.rotateYZBy(rot.X);
			// v.rotateXZBy(rot.Y);
			// v.rotateXYBy(rot.Z);

			Vector3 vrot = Vector3(
				((Real)xx / ((Real)polyCount - 1.0) * Radius * 2 - Radius),
				((Real)yy / ((Real)polyCount - 1.0) * Radius * 2 - Radius),
				Radius).getHorizontalAngle();

			Vector3 = Vector3(0, 0, Radius);

			if (Direction.Y == 0) {
				//v.rotateYZBy(rot.X + vrot.X);
				//v.rotateXZBy(rot.Y + vrot.Y);
			}
			else
			{
				v.rotateYZBy(vrot.X);
				v.rotateXZBy(vrot.Y - 90 * Direction.Y);
				v.rotateXYBy(90);
			}

			vtx.Pos.set(v.X, v.Y, v.Z);

			vtx.TCoords.set((f32)xx / ((f32)polyCount - 1), polyCount - ((f32)yy / ((f32)polyCount - 1)));
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

	// Recalculate normals
	for (u32 i = 0; i < buffer->Indices.size(); i += 3)
	{
		const core::vector3df normal = core::plane3d<f32>(
			buffer->Vertices[buffer->Indices[i+0]].Pos,
			buffer->Vertices[buffer->Indices[i+1]].Pos,
			buffer->Vertices[buffer->Indices[i+2]].Pos).Normal;

		buffer->Vertices[buffer->Indices[i+0]].Normal = normal;
		buffer->Vertices[buffer->Indices[i+1]].Normal = normal;
		buffer->Vertices[buffer->Indices[i+2]].Normal = normal;
	}

	buffer->recalculateBoundingBox();
	buffer->setHardwareMappingHint(EHM_STATIC);

	return buffer;
}

IMesh* Planet::createPlanetMesh(const f32 Radius)
{
	SMesh* mesh 		= new SMesh;
	SMeshBuffer* face 	= 0;

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(1, 0, 0));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/left.png"));
	mesh->addMeshBuffer(face);
	face->drop();

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 1, 0));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/top.png"));
	mesh->addMeshBuffer(face);
	face->drop();

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 0, 1));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/back.png"));
	mesh->addMeshBuffer(face);
	face->drop();

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(-1, 0, 0));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/right.png"));
	mesh->addMeshBuffer(face);
	face->drop();

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, -1, 0));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/bottom.png"));
	mesh->addMeshBuffer(face);
	face->drop();

	face = createPlanetQLSCFaceMeshBuffer(Radius, vector3df(0, 0, -1));
	face->Material.setTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/front.png"));
	mesh->addMeshBuffer(face);
	face->drop();

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

void Planet::showLighting(const bool State)
{
	if (m_pSceneNode != 0)
		m_pSceneNode->setMaterialFlag(video::EMF_LIGHTING, State);

	m_pShowLighting = State;
}

void Planet::showOutline(const bool State)
{
	// TODO: Show/hide mesh lighting
	m_pShowOutline = State;
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
