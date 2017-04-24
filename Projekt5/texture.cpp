#include "texture.h"
#include "IO.h"
#include "errors.h"
#include "picoPng.h"

namespace engineX {

	texture::texture(std::string name)
	{
		loadTexture(name);
	}


	texture::~texture()
	{
	}


	void texture::bindTexture() {
		glBindTexture(GL_TEXTURE_2D, textureID);
	}


	void texture::uploadTextureData(std::vector<unsigned char> pixelData) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(pixelData[0]));
	}
	void texture::setTextureParameter(int name, int state) {
		glTexParameteri(GL_TEXTURE_2D, name, state);
	}

	GLuint texture::loadTexture(std::string filePath) {


		GLTexture texture = {};// all 0

		std::vector<unsigned char> in;
		std::vector<unsigned char> out;

		if (IO::readFileToBuffer(filePath, in) == false) {
			fatalError("Failed to load PNG!");
		}

		int errorCode = decodePNG(out, textureWidth, textureHeight, &in[0], in.size());
		if (errorCode != 0) {
			fatalError("decodePNG failed with error: " + std::to_string(errorCode));
		}

		glGenTextures(1, &(texture.id));
		textureID = texture.id;
		//Generate and bind the texture
		bindTexture();
		//Upload the buffer's content to the VRAM
		uploadTextureData(out);
		//Apply filters
		setTextureParameter(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		setTextureParameter(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		//Important!! without lines underneath model looks like shit
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//Unbind texture
		glBindTexture(GL_TEXTURE_2D, 0);
		return 1;
	}
}