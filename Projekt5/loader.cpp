#include "loader.h"

namespace engineX {
	loader::loader()
	{
	}


	loader::~loader()
	{
	}

	int loader::loadToVAO(float positions[], float textureCoords[]) {
		int vaoID = createVAO();
		storeDataInAttribList(0, 2, positions); //2d!
		storeDataInAttribList(1, 2, textureCoords);
		unbindVAO();
		return vaoID;
	}

	rawModel loader::loadToVAO(float positions[], float textureCoords[], float normals[], int indices[]) {
		int vaoID = createVAO();
		bindIndicesBuffer(indices);
		storeDataInAttribList(0, 3, positions);
		storeDataInAttribList(1, 2, textureCoords);
		storeDataInAttribList(2, 3, normals);
		unbindVAO();
		return rawModel(vaoID, sizeof(indices)/(sizeof(int)));
	}

	rawModel loader::loadToVAO(float positions[], int dim) {
		int vaoID = createVAO();
		storeDataInAttribList(0, dim, positions);
		unbindVAO();
		return rawModel(vaoID, (sizeof(positions)/(sizeof(float))) / dim);
	}

	int loader::loadTexture(std::string fileName) {
		texture *txt = new texture(fileName);
		int textureID = txt->getID();

		//enable mipmaping
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		textures.push_back(textureID);
		return textureID;

	}

	int loader::loadCubeMap(std::string textureStrings[]) {
		GLuint texID;
		glGenTextures(1, &texID);

		glActiveTexture(GL_TEXTURE0);

		glBindTexture(GL_TEXTURE_CUBE_MAP, texID);
		GLTexture* txt = new GLTexture();

		for (int i = 0; i<sizeof(textureStrings)/sizeof(std::string); i++) {
			std::vector<unsigned char> data = decodeTextureFile(textureStrings[i], txt);
			//Param 1 -> 1 of 6 
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, txt->width, txt->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(data[0]));
		}
		//To make it smooth
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		//say no to lines on the edges!
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		textures.push_back(texID);
		return 1;
	}

	//duplicate, in future the method from texture class will be used
	std::vector<unsigned char>& loader::decodeTextureFile(std::string fileName, GLTexture* txt) {
		

		std::vector<unsigned char> bufferIn;
		std::vector<unsigned char> bufferOut;
	
		IO::readFileToBuffer(fileName, bufferIn);
		int errorCode = decodePNG(bufferOut,txt->width, txt->height, &bufferIn[0], bufferIn.size());
		if (errorCode != 0) {
			fatalError("decodePNG failed with error: " + std::to_string(errorCode));
		}

		return bufferOut;
	}

	int loader::createVAO() {
		GLuint vaoID;
		glGenVertexArrays(1, &vaoID);
		vaos.push_back(vaoID);
		glBindVertexArray(vaoID);
		return vaoID;
	}

	void loader::cleanUp() {

		for (GLuint vao : vaos) {
			glDeleteVertexArrays(1,&vao);
		}

		for (GLuint vbo : vbos) {
			glDeleteBuffers(1, &vbo);
		}
		for (GLuint texture : textures) {
			glDeleteTextures(1, &texture);
		}
	}

	void loader::storeDataInAttribList(int attribNumber, int size, float data[]) {
		GLuint vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		std::vector<float> buffer = storeDataInFB(data);
		glBufferData(GL_ARRAY_BUFFER, buffer.size(), &buffer.front(), GL_STATIC_DRAW); // static means I will not edit the data when it is stored in buffer
		glVertexAttribPointer(attribNumber, size, GL_FLOAT, false, 0, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0); // Unbind the vbo
	}

	void loader::unbindVAO() {
		glBindVertexArray(0);

	}

	void loader::bindIndicesBuffer(int indices[]) {
		GLuint vboID;
		glGenBuffers(1, &vboID);
		vbos.push_back(vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		std::vector<int> buffer = storeDataInIntBuffer(indices);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, buffer.size(), &buffer.front(), GL_STATIC_DRAW);

	}

	std::vector<int>& loader::storeDataInIntBuffer(int data[]) {
		int size = sizeof(data) / sizeof(int);
		std::vector<int> buffer(data, data +size);
		return buffer;
	}

	std::vector<float>& loader::storeDataInFB(float data[]) {
		int size = sizeof(data) / sizeof(float);
		std::vector<float> buffer(data, data + size);
		return buffer;
	}
}