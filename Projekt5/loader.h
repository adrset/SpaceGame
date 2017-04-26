#pragma once
#include <vector>
#include "GLTexture.h"
#include "rawModel.h"
#include "texture.h"
#include "IO.h"
#include "picoPng.h"
#include "errors.h"

namespace engineX {
	class loader
	{
	public:
		loader();
		~loader();
		int loadToVAO(float positions[], float textureCoords[]);
		rawModel loadToVAO(float positions[], float textureCoords[], float normals[], int indices[]);
		rawModel loadToVAO(float positions[], int dim);
		int loadTexture(std::string fileName);
		void cleanUp();
		int loadCubeMap(std::string textures[]);
	private:
		std::vector<GLuint> vaos;
		std::vector<GLuint> vbos;
		std::vector<GLuint> textures;
		int createVAO();
		void storeDataInAttribList(int attribNumber, int size, float data[]);
		void unbindVAO();
		void bindIndicesBuffer(int indices[]);
		std::vector<unsigned char>& loader::decodeTextureFile(std::string fileName, GLTexture* txt);
		std::vector<int>& storeDataInIntBuffer(int data[]);
		std::vector<float>& storeDataInFB(float data[]);
	};

}