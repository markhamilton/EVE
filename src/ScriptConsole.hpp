// This is not intended to replace the Ogre/system logging
// But augment it with a scripting interface and scrollback in-game

#ifndef CONSOLE_HPP
#define CONSOLE_HPP

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

	void saveToFile(const String outputFile);

private:
};

#endif
