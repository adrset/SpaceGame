#include "window.h"
namespace engineX {
	class game
	{
	private:
		std::string title;
		void loop();
		void cleanUp();
		window* m_window = nullptr;
	public:
		static int st_width;
		static int st_height;
		void run();
		game(int width, int height, std::string title);
		~game();
	};
}
