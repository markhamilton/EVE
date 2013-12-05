#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#define MAX_CONSOLE_MESSAGES 5000

#include <string>
#include <stdio.h>
#include <OGRE/Ogre.h>

using namespace Ogre;

enum ConsoleMessageType
{
	CMT_STANDARD = 0,
	CMT_GFX,
	CMT_ERROR,
};

class EveConsole
{
public:
	EveConsole();
	~EveConsole();

	void saveToFile(const String Output);

private:
};

#endif
