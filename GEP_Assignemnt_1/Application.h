#ifndef _MEESEEKS_ENGINE_APPLICATION_H_
#define _MEESEEKS_ENGINE_APPLICATION_H_

#include "platform.h"

#include <memory>
#include <vector>
#include <string>


namespace meeseeks
{

	namespace engine
	{


		class Display;
		class Application;

		struct Context
		{
			bool running;

			int argc; // Argument count (number of arguments passed to the program in main)
			std::vector<std::string> argv; // Argument vector (each string is an argument passed to program in main)

										   // Will later hold data paths and resources
		};


		// Programming with Extra Steps

		class Application
		{

			friend class meeseeks::engine::Display;

		public:
			static void init(int argc, char* argv[]); // Initialise context, glut and glew 
			static void destroy();
			static void run();
			static void quit();
			static int getArgc();
			static std::string getArgv(int i);
			static void setTitle(std::string title);

		private:
			static shared<Context> context;

			static void reshape(int width, int height); // Set Screen dimensions
			static void engineDisplay();

		};


	}
}

#endif // !_MEESEEKS_ENGINE_APPLICATION_H_


