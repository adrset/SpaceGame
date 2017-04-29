#include <cmath>
#include "utils.h"


namespace engineX {

	const float utils::PI = 3.14159265359f;
	utils::utils()
	{
	}


	utils::~utils()
	{
	}

	glm::mat4 utils::createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale) {
		glm::mat4 matrix;
		matrix = glm::translate(matrix, translation);
		matrix = glm::rotate(matrix, utils::toRadians(rx), glm::vec3(1.0f, 0.0f, 0.0f));
		matrix = glm::rotate(matrix, utils::toRadians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
		matrix = glm::rotate(matrix, utils::toRadians(rz), glm::vec3(0.0f, 0.0f, 1.0f));
		matrix = glm::scale(matrix, glm::vec3(scale));

		return matrix;
	}

	glm::mat4 utils::createTransformationMatrix(glm::vec2 translation, glm::vec2 scale) {
		glm::mat4 matrix;
		matrix = glm::translate(matrix, glm::vec3(translation, 0));
		matrix = glm::scale(matrix, glm::vec3(scale, 1));
		return matrix;
	}

	glm::mat4 utils::createViewMatrix(camera3d camera) {
		glm::mat4 viewMatrix;
		viewMatrix = glm::rotate(viewMatrix, (float)utils::toRadians(camera.getPitch()), glm::vec3(1, 0, 0));
		viewMatrix = glm::rotate(viewMatrix, (float)utils::toRadians(camera.getYaw()), glm::vec3(0, 1, 0));
		glm::vec3 cameraPos = camera.getPosition();
		glm::vec3 negativeCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
		viewMatrix = glm::translate(viewMatrix, negativeCameraPos);
		return viewMatrix;
	}

	float utils::toRadians(float degree) {
		return (degree * PI / 180.0f);
	}
}