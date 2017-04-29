#include "resourceManager.h"

namespace engineX {

	resourceManager::resourceManager()
	{
	}


	resourceManager::~resourceManager()
	{
	}

	std::map<std::string, int> resourceManager::m_textureMap;
	std::map<std::string, rawModel> resourceManager::m_objectMap;

	rawModel& resourceManager::loadOBJ(std::string name) {

		//look for texture
		auto mit = m_objectMap.find(name);

		if (mit == m_objectMap.end()) {
			rawModel model = OBJLoader::loadObjModel(name);
			m_objectMap.insert(make_pair(name, model));
			return model;
		}
		return mit->second;
	}

	int resourceManager::loadTexture(std::string name, loader l) {

		//look for texture
		auto mit = m_textureMap.find(name);

		if (mit == m_textureMap.end()) {
			int textureID = l.loadTexture(name);
			m_textureMap.insert(make_pair(name, textureID));
			return textureID;
		}
		return mit->second;
	}

}