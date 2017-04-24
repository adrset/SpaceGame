#include <iostream>
#include "staticShader.h"
#include "game.h"
#include "OBJLoader.h"
namespace engineX {


	game::game(int width, int height, std::string title) : width(width), height(height), title(title)
	{
		run();
		staticShader *a = new staticShader();
		rawModel model = OBJLoader::loadObjModel("planet.obj");
		loop();
	}


	game::~game()
	{
		delete m_window;
	}

	void game::cleanUp() {
		m_window->closeWindow();
	}

	void game::run() {
		m_window = new window(width,height,title);
	}

	 void game::loop() {
		 while (!glfwWindowShouldClose(m_window->getWindowID()))
		 {
			 /* Render here */
			 glfwPollEvents();

			 // Render
			 // Clear the colorbuffer
			 glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			 glClear(GL_COLOR_BUFFER_BIT);

			 // Swap the screen buffers
			 glfwSwapBuffers(m_window->getWindowID());
		 }
		cleanUp();

	}
}

