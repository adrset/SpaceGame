#include <iostream>
#include <Projekt5/staticShader.h>
#include <Projekt5/resourceManager.h>
#include "game.h"

using namespace engineX;


	game::game(int width, int height, std::string title): title(title)
	{
		st_width = width;
		st_height = height;
		run();
		staticShader *a = new staticShader();
		rawModel model = resourceManager::loadOBJ("planet.obj");
		loop();
	}


	game::~game()
	{
		delete m_window;
	}

	void game::cleanUp() {
		m_window->closeWindow();
	}

	int game::st_width=0;
	int game::st_height=0;

	void game::run() {
		m_window = new window(st_width,st_height,title);
	}

	 void game::loop() {
		 while (!glfwWindowShouldClose(m_window->getWindowID()))
		 {
			 /* Render here */
			 glfwPollEvents();

			 std::cout<<m_window->m_input.isMouseKeyPressed(GLFW_MOUSE_BUTTON_1);
			 m_window->m_input.update();
			 // Render
			 // Clear the colorbuffer
			 glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			 glClear(GL_COLOR_BUFFER_BIT);

			 // Swap the screen buffers
			 glfwSwapBuffers(m_window->getWindowID());
		 }
		cleanUp();

	}

