#include "Planet.hpp"

Planet::Planet()
{

}

Planet::Planet(ISceneNode* parent, ISceneManager* mgr, s32 id)
		//: scene::ISceneNode(parent, mgr, id)
{
	Material.Wireframe = false;
	Material.Lighting = false;

	Vertices[0] = video::S3DVertex(0,0,10, 1,1,0,
			video::SColor(255,0,255,255), 0, 1);
	Vertices[1] = video::S3DVertex(10,0,-10, 1,0,0,
			video::SColor(255,255,0,255), 1, 1);
	Vertices[2] = video::S3DVertex(0,20,0, 0,1,1,
			video::SColor(255,255,255,0), 1, 0);
	Vertices[3] = video::S3DVertex(-10,0,-10, 0,0,1,
			video::SColor(255,0,255,0), 0, 0);

	Box.reset(Vertices[0].Pos);
	for (s32 i=1; i<4; ++i)
		Box.addInternalPoint(Vertices[i].Pos);
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

Planet::Planet(video::IVideoDriver* Driver, scene::ISceneManager* Smgr, wchar_t* Name, const io::path &Texture, const f32 Radius)
{
	// TODO: Create Quadrilateralized spherical cube
	// TODO: Determine appropriate poly count from relative size
	m_pName = Name;

	IMeshSceneNode* planet = Smgr->addSphereSceneNode(Radius, 160, 0, -1, vector3df(0, 0, 0), vector3df(0, 0, 0));
	planet->setMaterialFlag(video::EMF_LIGHTING, false);
	planet->setMaterialTexture(0, Driver->getTexture(Texture));
}

void Planet::setName(wchar_t* Name)
{
	m_pName = Name;
}
wchar_t *Planet::getName()
{
	return m_pName;
}

void Planet::setWireFrame(const bool State)
{
	// TODO: setWireFrame() -- Make sure to blank texture and set material flag to video::EMF_WIREFRAME
}
