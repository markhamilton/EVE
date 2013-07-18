// TODO: Load planet data dynamically via a kinetic snapshot of our galaxy (XML format)
// TODO: Update scene
// TODO: Update GUI
// TODO: FPS Counter
// TODO: Logging
// TODO: GUI

#include "SimApp.hpp"

int main(int argc, char **argv)
{
	GLFWwindow* window;

	if (!glfwInit()) {
		printf("glfw failed init");
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow(640, 480, "Eve Flight Simulatior", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		printf("Can't create window");
		return -1;
	}

	glfwMakeContextCurrent(window);

	SimApp app(window);
	app.createScene();

	while (!glfwWindowShouldClose(window))
	{
		app.renderScene();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

SimApp::SimApp(GLFWwindow* window)
{
	m_pPlanetManager = 0;
	m_pWindow = window;
}
 
SimApp::~SimApp()
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
	float ratio;
	int width, height;

	glfwGetFramebufferSize(m_pWindow, &width, &height);
	ratio = width / (float)height;

	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glLoadIdentity();
	glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.f, 0.f, 0.f);
	glVertex3f(-0.6f, -0.4f, 0.f);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(0.6f, -0.4f, 0.f);
	glColor3f(0.f, 0.f, 1.f);
	glVertex3f(0.f, 0.6f, 0.f);
	glEnd();

	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}

bool SimApp::init(const std::string wndTitle)
{
	return true;
}
