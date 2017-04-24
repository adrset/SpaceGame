#include <iostream>
#include "window.h"
#include "errors.h"

namespace engineX {

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	window::~window() {
		std::cout << "Deleting window" << std::endl;
	}

	window::window(int width, int height, std::string title) {

		info(width, height, title);

		if (!glfwInit())
		{
			glfwTerminate();
			fatalError("Could not init GLFW");
		}

		glfwSetErrorCallback(glfwError);

		m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		
		if (!m_window)
		{
			closeWindow();
			fatalError("Could not create window!");
		}

		glfwSetKeyCallback(m_window, key_callback);

		glfwMakeContextCurrent(m_window);

		glewExperimental = GL_TRUE;

		if (glewInit() != 0.0) {
			fatalError("Failed to initialize GLEW!");
		}

		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_window, (int)(0.5 * (vidmode->width - width)), int((0.5*(vidmode->height - height ))));

	}

	void window::closeWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
}