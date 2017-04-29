#pragma once
#include <glm/mat4x4.hpp>
#include <glm/gtx/transform.hpp>
#include "utils.h"
#include "camera3d.h"
namespace engineX {
	class utils
	{
	public:
		static const float PI;
		utils();
		~utils();
		static float toRadians(float degree);

		static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float scale);

		static glm::mat4 createTransformationMatrix(glm::vec2 translation, glm::vec2 scale);

		static glm::mat4 createViewMatrix(camera3d camera);
	};

}
