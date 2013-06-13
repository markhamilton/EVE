#include "SimApp.hpp"

#ifdef WINDOWS
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
int main(int argc, char **argv)
#endif
{
	SimApp app;
	try	
	{
		app.start();
	}
	catch(std::exception& e)
    {
#ifdef WINDOWS
        MessageBoxA(NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        fprintf(stderr, "An exception has occurred: %s\n", e.what());
#endif
    }
 
    return 0;
}
