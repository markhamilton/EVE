// TODO: Trap logging events from Irrlicht and bring them into here
// TODO: Load default console font from assets folder

#include "ScriptConsole.hpp"

EveConsole::EveConsole()
{
	m_pMessageFirstIndex = 0;
	m_pMessageCount = 0;
}

EveConsole::~EveConsole()
{

}

void EveConsole::writeLine(stringw text, const ConsoleMessageType messageType)
{
	if( m_pMessageCount < MAX_CONSOLE_MESSAGES )
	{
		m_pMessage[m_pMessageCount] = text;
		m_pMessageType[m_pMessageCount] = messageType;
		m_pMessageCount++;
	}
	else
	{
		m_pMessage[m_pMessageFirstIndex] = text;
		m_pMessageType[m_pMessageFirstIndex] = messageType;
		m_pMessageFirstIndex++;
	}
}

void EveConsole::saveToFile(const io::path &Output)
{
	// TODO: Open file

	// TODO: close file
}
