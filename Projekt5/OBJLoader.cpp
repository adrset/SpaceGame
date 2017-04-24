#include <sstream>
#include <iostream>
#include "OBJLoader.h"
#include "IO.h"

namespace engineX {

	
	std::vector<std::string> split(const std::string &str, char sep) {
		std::vector<std::string> tokens;
		std::size_t start = 0, end = 0;
		while ((end = str.find(sep, start)) != std::string::npos) {
			tokens.push_back(str.substr(start, end - start));
			start = end + 1;
		}
		tokens.push_back(str.substr(start));
		return tokens;
	}

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
		unsigned int faceIndex;
		float *textureArray = nullptr;
		float *normalsArray = nullptr;

		//decode vertices, vertex textures and indices
		for (unsigned int i = 0; i < in.size();i++) {
			std::string *line = &in[i];
			ss << *line;
			if (line->compare(0, 2, "v ") == 0){
				glm::vec3 vertex;
				ss >> trash >> vertex.x >> vertex.y >> vertex.z;
				vertices.push_back(vertex);
				ss = std::stringstream();
			}
			else if (line->compare(0, 3, "vn ") == 0) {
				glm::vec3 normal;
				ss >> trash >> normal.x >> normal.y >> normal.z;
				normals.push_back(normal);
				ss = std::stringstream();
			}
			else if (line->compare(0, 3, "vt ") == 0) {
				glm::vec2 texture;
				ss >> trash >> texture.x >> texture.y;
				textures.push_back(texture);
				ss = std::stringstream();
			}
			else if (line->compare(0, 2, "f ") == 0) {
				textureArray = new float[vertices.size() * 2];
				normalsArray = new float[vertices.size() * 3];
				faceIndex = i;
				break;
			}
		}

		for (unsigned int i = faceIndex; i < in.size(); i++) {
			std::string *line = &in[i];
			std::istringstream sstream(*line);
			std::string token;
			std::string face[3];
			glm::vec3 vertexFaces[3];
			int faces[9];
			int jj = 0;
			while (sstream >> token) {
				if (token != "f") {
					face[jj] = token;
					jj++;
				}
			}
			jj = 0;
			for (int i = 0; i < 3; i++) {
				for (std::string s : split(face[i], '/')) {
					if (!s.empty()) {
						faces[jj] = std::stoi(s);
						jj++;
					}
				}
				processVertex(faces, indices, textures, normals, textureArray, normalsArray);
				
				jj = 0;
			}

			
			
		}

		delete[] textureArray;
		delete[] normalsArray;

		return rawModel(1,11);

	}
	void OBJLoader::processVertex(int (vertices)[], std::vector<int> &indices, std::vector<glm::vec2> &textures, std::vector<glm::vec3> &normals, float*  (&textureArray), float*  (&normalsArray)){
		int currentVertexPointer = vertices[0]-1;
		indices.push_back(currentVertexPointer);
		glm::vec2 currentTex = textures[vertices[1]-1];
		textureArray[currentVertexPointer * 2] = currentTex.x;
		textureArray[currentVertexPointer * 2 + 1] = 1 - currentTex.y;
		glm::vec3 currentNorm = normals[vertices[2]-1];
		normalsArray[currentVertexPointer * 3] = currentNorm.x;
		normalsArray[currentVertexPointer * 3 + 1] = currentNorm.y;
		normalsArray[currentVertexPointer * 3 + 2] = currentNorm.z;
	}
	
}