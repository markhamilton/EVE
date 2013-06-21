#include "Planet.hpp"

Planet::Planet()
{
}

Planet::Planet(ISceneNode* parent, ISceneManager* mgr, s32 id)
		//: scene::ISceneNode(parent, mgr, id)
{
	m_pMaterial.Wireframe = false;
	m_pMaterial.Lighting = false;

    m_pVertices = vector<S3DVertex>(4);
	m_pVertices[0] = video::S3DVertex(0,0,10, 1,1,0,
			video::SColor(255,0,255,255), 0, 1);
	m_pVertices[1] = video::S3DVertex(10,0,-10, 1,0,0,
			video::SColor(255,255,0,255), 1, 1);
	m_pVertices[2] = video::S3DVertex(0,20,0, 0,1,1,
			video::SColor(255,255,255,0), 1, 0);
	m_pVertices[3] = video::S3DVertex(-10,0,-10, 0,0,1,
			video::SColor(255,0,255,0), 0, 0);

	m_pBox.reset(m_pVertices[0].Pos);
	for (s32 i=1; i<4; ++i)
		m_pBox.addInternalPoint(m_pVertices[i].Pos);
}

Planet::Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, const stringw Name, const io::path &Texture, const f32 Radius)
{
	// TODO: Create Quadrilateralized spherical cube
	// TODO: Determine appropriate poly count from relative size
	m_pName = Name;

	IMeshSceneNode* planet = Smgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	planet->setMaterialFlag(video::EMF_LIGHTING, false);
	planet->setMaterialTexture(0, Driver->getTexture(Texture));
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

void Planet::setWireFrame(const bool State)
{
	// TODO: setWireFrame() -- Make sure to blank texture and set material flag to video::EMF_WIREFRAME
}
