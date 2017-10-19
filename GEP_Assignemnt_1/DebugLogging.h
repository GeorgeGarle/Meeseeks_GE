#ifndef _MEESEEKS_LOGGING_H_
#define _MEESEEKS_LOGGING_H_

#include <iostream>
#include <sstream>
// Used for Console Text Colour
#include <Windows.h>

enum logseverity
{

	dlERROR, dlWARNING, dlINFO, dlDEBUG, dlDEBUG1, dlDEBUG2, dlDEBUG3, dlDEBUG4

};

class DebugLogging
{



public:



	DebugLogging(logseverity _logseverity = dlERROR);
	~DebugLogging();

	std::string DebugSwitch(logseverity _logseverity);

	template <typename T>
	DebugLogging & operator<<(T const & value)
	{

		_sBuffer << value;
		return *this;

	}

	

private:

	std::ostringstream _sBuffer;


};

#define dLog(level) \
if (level > loglevel) ; \
else DebugLogging(level)


#endif
/*
#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <iostream>
#include <sstream>

/* consider adding boost thread id since we'll want to know whose writting and
* won't want to repeat it for every single call */

/* consider adding policy class to allow users to redirect logging to specific
* files via the command line
*/
/*
enum loglevel_e
{
	logERROR, logWARNING, logINFO, logDEBUG, logDEBUG1, logDEBUG2, logDEBUG3, logDEBUG4
};

class logIt
{
public:
	logIt(loglevel_e _loglevel = logERROR) {
		_buffer << _loglevel << " :"
			<< std::string(
				_loglevel > logDEBUG
				? (_loglevel - logDEBUG) * 4
				: 1
				, ' ');
	}

	template <typename T>
	logIt & operator<<(T const & value)
	{
		_buffer << value;
		return *this;
	}

	~logIt()
	{
		_buffer << std::endl;
		// This is atomic according to the POSIX standard
		// http://www.gnu.org/s/libc/manual/html_node/Streams-and-Threads.html
		std::cerr << _buffer.str();
	}

private:
	std::ostringstream _buffer;
};

extern loglevel_e loglevel;

#define log(level) \
if (level > loglevel) ; \
else logIt(level)

#endif*/


