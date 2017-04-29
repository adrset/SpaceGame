#pragma once
#include <map>
#include "OBJLoader.h"
#include "rawModel.h"
#include "loader.h"
namespace engineX {
	class resourceManager
	{
	public:
		resourceManager();
		~resourceManager();
		static rawModel& loadOBJ(std::string name);
		static int loadTexture(std::string name, loader l);
	private:
		static std::map<std::string, int> m_textureMap;
		static std::map<std::string, rawModel> m_objectMap;
	};

}