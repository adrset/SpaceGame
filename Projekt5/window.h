#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "inputManager.h"
namespace engineX {

	

	class window {
	private:
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		GLFWwindow* m_window;
		struct info {
			int width;
			int height;
			std::string title;
			info(int w, int h, std::string t) : width(w), height(h), title(t) {};
		};

		
	public:
		static inputManager m_input;
		GLFWwindow* getWindowID() const { return m_window; }
		void closeWindow();
		window(int width, int height, std::string title);
		~window();
	};

	
}