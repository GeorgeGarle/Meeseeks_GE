#include "DebugLogging.h"
#include <ctype.h>


/*

https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal

foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27*/

DebugLogging::DebugLogging(logseverity _logseverity)
{
	// Adds spaces depending on the severity / Log
	
	_sBuffer << DebugSwitch(_logseverity) << " :" << std::string(_logseverity > dlDEBUG ? (_logseverity - dlDEBUG) * 4 : 1, ' ');

}

DebugLogging::~DebugLogging()
{

	_sBuffer << std::endl;
	std::cerr << _sBuffer.str();

}

std::string DebugLogging::DebugSwitch(logseverity _logseverity)
{

	switch (_logseverity)
	{

	case dlINFO:
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);

		std::cout << "INFO";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

		return "\033[1; 33mINFO\033[0m";
		break;
	}

	default:
		break;
	}


	return "ERROR";

}



