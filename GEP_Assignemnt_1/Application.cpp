#include "Application.h"
#include "Display.h"
#include "platform.h"


#include <GL/glew.h>

#ifdef USE_GLUT
	#include <GL/freeglut.h>
#endif

#include <Windows.h>

namespace meeseeks
{

	namespace engine
	{

		shared<Context> Application::context;

		void Application::init(int argc, char* argv[])
		{
			// Create and initialise a new context
			context.reset(new Context());

			context->running = false;
			context->argc = argc;

			for (int i = 0; i < argc; i++)
			{
				context->argv.push_back(argv[i]);
			}

			// Initialise glut and display window

			Display::width = 800;
			Display::height = 600;

#ifdef USE_GLUT
			glutInit(&argc, argv);
			glutInitWindowSize(Display::width, Display::height);
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
			glutCreateWindow("Meeseeks Engine - Programming with Extra Steps");
			glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

			glutDisplayFunc(engineDisplay);
			glutReshapeFunc(reshape);
#endif



			// Initialise glew
			glewInit();

			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_CULL_FACE);
			glCullFace(GL_FRONT);
		}

		void Application::setTitle(std::string title)
		{
#ifdef USE_GLUT
			glutSetWindowTitle(title.c_str());
#endif
		}

		void Application::destroy()
		{
			// TODO: Running is a flag, not a reliable state
			if (context->running == true)
			{
				//throw Exception("Immediate shutdown not supported");
			}

			context.reset();
		}

		void Application::run()
		{
			if (context->running == true)
			{
				return;
			}

			context->running = true;

			glutMainLoop();

			context->running = false;
		}

		void Application::quit()
		{
			context->running = false;

			glutLeaveMainLoop();
		}

		int Application::getArgc()
		{
			return context->argc;
		}

		std::string Application::getArgv(int i)
		{
			return context->argv.at(i);
		}

		void Application::reshape(int width, int height)
		{
			Display::width = width;
			Display::height = height;
		}

		void Application::engineDisplay()
		{
			glClearColor(32.0f / 255.0f, 32.0f / 255.0f, 32.0f / 255.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glViewport(0, 0, Display::getDisplayW(), Display::getDisplayH());

			glutSwapBuffers();
		}



	}



}