#include "Display.h"
#include "Application.h"


namespace meeseeks
{

	namespace engine
	{

		
		int Display::width;
		int Display::height;

		int Display::getDisplayH()
		{

			return height;

		}

		int Display::getDisplayW()
		{

			return width;

		}

		void Display::SetResolution(int width, int height, bool fullscreen, int prefRefreshRate)
		{

			Application::reshape(width, height);

		}

	}



}

