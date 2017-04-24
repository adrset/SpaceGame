#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
class MasterRenderer
{

private:
	static float FOV;
	static float NEAR_PLANE;
	const static float FAR_PLANE;
	static float RED;
	static float GREEN;
	static float BLUE;
	glm::vec4 projectionMatrix;
	void render();
public:
	void enableCulling();
	void disableCulling();
	MasterRenderer();
	~MasterRenderer();
};

