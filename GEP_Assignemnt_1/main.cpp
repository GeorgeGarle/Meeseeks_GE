#include "Application.h"
//#include "Exception.h"
#include "platform.h"

#include "windows.h"
#include "DebugLogging.h"

#include <iostream>

namespace meeseeks
{

	namespace engine
	{

		void safe_main(int argc, char* argv[])
		{
			Application::init(argc, argv);

			Application::run();

			Application::destroy();
		}

	}

}

/*

void logTest(void) {
	loglevel_e loglevel_save = loglevel;

	loglevel = logDEBUG4;

	log(logINFO) << "foo " << "bar " << "baz";

	int count = 3;
	log(logDEBUG) << "A loop with " << count << " iterations";
	for (int i = 0; i != count; ++i)
	{
		log(logDEBUG1) << "the counter i = " << i;
		log(logDEBUG2) << "the counter i = " << i;
	}

	loglevel = loglevel_save;
}*/

logseverity loglevel = dlDEBUG4;

int main(int argc, char* argv[])
{
	//logTest();

	dLog(dlINFO) << "Farts" << "Test" << "All";
	meeseeks::engine::safe_main(argc, argv);

	return 0;
}
