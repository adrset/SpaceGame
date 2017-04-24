#include <sstream>
#include <iostream>
#include "OBJLoader.h"
#include "IO.h"

namespace engineX {

	OBJLoader::OBJLoader()
	{
	}


	OBJLoader::~OBJLoader()
	{
	}


	rawModel OBJLoader::loadObjModel(std::string fileName) {
		//slow
		std::vector<std::string> in;
		IO::readFileToVector(fileName, in);
		std::cout << "done";
		std::vector<glm::vec3> vertices;
		std::vector<int> indices;
		std::vector<glm::vec2> textures;
		std::vector<glm::vec3> normals;
		std::stringstream ss;
		std::string trash;
		std::string s[3];
		std::string tmp;
		for (std::string line : in) {
			ss << line;
			if (line.compare(0, 2, "v ") == 0){
				glm::vec3 vertex;
				ss >> trash >> vertex.x >> vertex.y >> vertex.z;
				vertices.push_back(vertex);
			}
			else if (line.compare(0, 3, "vn ") == 0) {
				glm::vec3 normal;
				ss >> trash >> normal.x >> normal.y >> normal.z;
				normals.push_back(normal);
			}
			else if (line.compare(0, 3, "vt ") == 0) {
				glm::vec2 texture;
				ss >> trash >> texture.x >> texture.y;
				textures.push_back(texture);
			}
			else if (line.compare(0, 2, "f ") == 0) {
				//to be contiuned
			}
			
		}

		return rawModel(1,11);

	}
	void OBJLoader::processVertex(double vertices[], std::vector<int> indices, std::vector<glm::vec2> textures, std::vector<glm::vec3> normals, float* textureArray, float* normalsArray) {
		int currentVertexPointer = vertices[0];
		indices.push_back(currentVertexPointer);
		glm::vec2 currentTex = textures[vertices[1]];
		textureArray[currentVertexPointer * 2] = currentTex.x;
		textureArray[currentVertexPointer * 2 + 1] = 1 - currentTex.y;
		glm::vec3 currentNorm = normals[vertices[2]];
		normalsArray[currentVertexPointer * 3] = currentNorm.x;
		normalsArray[currentVertexPointer * 3 + 1] = currentNorm.y;
		normalsArray[currentVertexPointer * 3 + 2] = currentNorm.z;
	}
	
}