#ifndef _MEESEEKS_ENGINE_DISPLAY_H_
#define _MEESEEKS_ENGINE_DISPLAY_H_

namespace meeseeks
{

	namespace engine
	{

		class Application;


		class Display
		{

			friend class Application;

		public:

			static int getDisplayW();
			static int getDisplayH();
			static void SetResolution(int width, int height, bool fullscreen = true, int prefRefreshRate = 0);

		private:

			static int width;
			static int height;
			static bool screenMode;
			static int refreshRate;

		};




	}




}








#endif // !_MEESEEKS_ENGINE_DISPLAY_H_