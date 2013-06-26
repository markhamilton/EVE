#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#define MAX_CONSOLE_MESSAGES 5000

#include <string>
#include <stdio.h>

using namespace std;

enum ConsoleMessageType
{
	CMT_STANDARD = 0,
	CMT_ERROR,
	CMT_GFX,
};

class EveConsole
{
public:
	EveConsole();
	~EveConsole();

	// void saveToFile(const io::path &Output);
	void writeLine(Ogre::String text, const ConsoleMessageType messageType);

private:
	// Circular buffer
	int					m_pMessageFirstIndex;
	int 				m_pMessageCount;
	Ogre::String		m_pMessage[MAX_CONSOLE_MESSAGES];
	ConsoleMessageType 	m_pMessageType[MAX_CONSOLE_MESSAGES];
};

#endif