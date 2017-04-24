#include "window.h"
namespace engineX {
	class game
	{
	private:
		int width;
		int height;
		std::string title;
		void loop();
		void cleanUp();
		window* m_window = nullptr;
	public:
		void run();
		game(int width, int height, std::string title);
		~game();
	};
}
