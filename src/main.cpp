#include <Ogre.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreFontManager.h>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv)
#endif
{
	Root *root = new Root();
	if(!root->showConfigDialog())
	{
		return 0;
	}
	RenderWindow *renderWindow = root->createRenderWindow("FlightSim", 640, 480, false);
	SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);

	Camera *mainCam = sceneMgr->createCamera("MainCam");
	ViewPort *vp = renderWindow->addViewPort(mainCam);


	return 0;
}
