#pragma once
#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include "rawModel.h"
namespace engineX {
	class OBJLoader
	{
	public:
		static rawModel loadObjModel(std::string fileName);
		OBJLoader();
		~OBJLoader();
	private:
		static void processVertex(double vertices[], std::vector<int> indices, std::vector<glm::vec2> textures, std::vector<glm::vec3> normals, float* textureArray, float* normalsArray);

	};
}