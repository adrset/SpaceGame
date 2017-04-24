#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
namespace engineX {

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	class window {
	private:
		GLFWwindow* m_window;
		struct info {
			int width;
			int height;
			std::string title;
			info(int w, int h, std::string t) : width(w), height(h), title(t) {};
		};
	public:
		GLFWwindow* getWindowID() const { return m_window; }
		void closeWindow();
		window(int width, int height, std::string title);
		~window();
	};

	
}