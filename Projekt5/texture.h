#pragma once
#include <string>
#include <vector>
#include <GL/glew.h>
#include "GLTexture.h"
namespace engineX {
	class texture
	{
	public:
		texture(std::string fileName);
		~texture();
		GLuint getID() const { return textureID; }
		int getTextureWidth() const { return textureWidth; }
		int getTextureHeight() const { return textureHeight; }
		void bindTexture();
	private:
		GLuint textureID;
		unsigned long textureWidth;
		unsigned long textureHeight;

		void uploadTextureData(std::vector<unsigned char> pixelData);
		void setTextureParameter(int name, int state);
		GLuint loadTexture(std::string filePath);
	};
}

