#include <iostream>
#include "window.h"
#include "errors.h"

namespace engineX {

	inputManager window::m_input;

	void window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		(action != GLFW_RELEASE) ? m_input.pressMouseKey(button) : m_input.releaseMouseKey(button);
	}

	void window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		m_input.addScroll(glm::vec2(xoffset, yoffset));
	}

	void window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(action != GLFW_RELEASE) ? m_input.pressKey(key): m_input.releaseKey(key);
	}

	void window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		m_input.setMouseCoords((float)xpos, (float)ypos);
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

		glfwMakeContextCurrent(m_window);

		//glfwSwapInterval(0);
		glewExperimental = GL_TRUE;

		if (glewInit() != 0.0) {
			fatalError("Failed to initialize GLEW!");
		}

		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_window, (int)(0.5 * (vidmode->width - width)), int((0.5*(vidmode->height - height ))));

		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);

	}


	void window::closeWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
}