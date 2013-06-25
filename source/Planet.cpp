// TODO: Create Quadrilateralized spherical cube

#include "Planet.hpp"

Planet::Planet()
{
	m_pSceneNode 		= 0;

	m_pShowWireframe 	= false;
	m_pShowBoundingBox 	= false;
	m_pShowNormal 		= false;
	m_pShowVelocity 	= false;
}

// Planet::Planet(ISceneNode* parent, ISceneManager* mgr, s32 id)
// 		//: scene::ISceneNode(parent, mgr, id)
// {
// 	m_pMaterial.Wireframe = false;
// 	m_pMaterial.Lighting = false;

//     m_pVertices = vector<S3DVertex>(4);
// 	m_pVertices[0] = video::S3DVertex(0,0,10, 1,1,0,
// 			video::SColor(255,0,255,255), 0, 1);
// 	m_pVertices[1] = video::S3DVertex(10,0,-10, 1,0,0,
// 			video::SColor(255,255,0,255), 1, 1);
// 	m_pVertices[2] = video::S3DVertex(0,20,0, 0,1,1,
// 			video::SColor(255,255,255,0), 1, 0);
// 	m_pVertices[3] = video::S3DVertex(-10,0,-10, 0,0,1,
// 			video::SColor(255,0,255,0), 0, 0);

// 	m_pBox.reset(m_pVertices[0].Pos);
// 	for (s32 i=1; i<4; ++i)
// 		m_pBox.addInternalPoint(m_pVertices[i].Pos);
// }

// SMesh* createCubeMesh(f32 cubeSize = 5.f)
// {
// 	video::SColor cubeColor(255,255,255,255);

// 	SMeshBuffer* buffer = new SMeshBuffer();
// 	SMeshBuffer* buffer2 = new SMeshBuffer();
// 	u16 u[6] = { 0,2,1, 0,3,2};
// 	u16 u2[6] = {0,11,10, 0,10,7};

// 	for (s32 i=0; i<6; ++i)
// 	{
// 		buffer->Indices.push_back( u[i] );
// 		buffer2->Indices.push_back( u2[i] );
// 	}

// 	buffer->Vertices.set_used(12);
// 	buffer->Vertices[0] = video::S3DVertex(0,0,0, -1,-1,-1, cubeColor, 0, 1);
// 	buffer->Vertices[1] = video::S3DVertex(1,0,0, 1,-1,-1, cubeColor, 1, 1);
// 	buffer->Vertices[2] = video::S3DVertex(1,1,0, 1, 1,-1, cubeColor, 1, 0);
// 	buffer->Vertices[3] = video::S3DVertex(0,1,0, -1, 1,-1, cubeColor, 0, 0);
// 	buffer->Vertices[4] = video::S3DVertex(1,0,1, 1,-1, 1, cubeColor, 0, 1);
// 	buffer->Vertices[5] = video::S3DVertex(1,1,1, 1, 1, 1, cubeColor, 0, 0);

// 	buffer2->Vertices[0] = video::S3DVertex(0,1,1, -1, 1, 1, cubeColor, 1, 0);
// 	buffer2->Vertices[1] = video::S3DVertex(0,0,1, -1,-1, 1, cubeColor, 1, 1);
// 	buffer2->Vertices[2] = video::S3DVertex(0,1,1, -1, 1, 1, cubeColor, 0, 1);
// 	buffer2->Vertices[3] = video::S3DVertex(0,1,0, -1, 1,-1, cubeColor, 1, 1);
// 	buffer2->Vertices[4] = video::S3DVertex(1,0,1, 1,-1, 1, cubeColor, 1, 0);
// 	buffer2->Vertices[5] = video::S3DVertex(1,0,0, 1,-1,-1, cubeColor, 0, 0);

// 	buffer->BoundingBox.reset(0,0,0);

// 	SMesh* cubeMesh = new SMesh();
// 	cubeMesh->addMeshBuffer(buffer);
// 	cubeMesh->addMeshBuffer(buffer2);

// 	return cubeMesh;

// 	// cubeSceneNode->getMaterial(0).Textures[0] = texture1
// 	// cubeSceneNode->getMaterial(1).Textures[0] = texture2
// }

Planet::Planet(IrrlichtDevice* Device, const stringw Name, const io::path &Texture, const f32 Radius)
{
	m_pDevice = Device;
	m_pSMgr = Device->getSceneManager();
	m_pDriver = Device->getVideoDriver();

	m_pName = Name;

	// m_pSceneNode = m_pSMgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	m_pSceneNode = m_pSMgr->addCubeSceneNode(Radius, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	m_pSceneNode->setMaterialFlag(video::EMF_LIGHTING, false);

	m_pSceneNode->setMaterialTexture(0, m_pDriver->getTexture("../assets/cubemap/earth/top.png"));
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