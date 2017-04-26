#pragma once
namespace engineX {
	class textureCache
	{
	public:
		textureCache();
		~textureCache();
		GLTexture getTexture(std::string texturePath);
	private:
		std::map<std::string, GLTexture> _textureMap;
	};

}