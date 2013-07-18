// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)
// TODO: Update scene
// TODO: Update GUI
// TODO: FPS Counter
// TODO: Logging
// TODO: GUI

#include "SimApp.hpp"

int main(int argc, char **argv)
{
	SimApp app;
	app.start();


	return 0;
}

SimApp::SimApp()
{
	m_pPlanetManager = 0;
}

SimApp::~SimApp()
{
}

void SimApp::start()
{
}

void SimApp::createScene()
{
	//m_pLog->logMessage("Creating scene...");
	// TODO: Init scene, camera, gui, simulation models, lighting
	// TODO: Load scene objects here
	m_pPlanetManager = new PlanetManager();
	// m_pPlanetManager->addPlanet("earth", 40.0f, Vector3f(0, 0, 0));
}

void SimApp::renderScene()
{

}

bool SimApp::init(const std::string wndTitle)
{
	return true;
}
