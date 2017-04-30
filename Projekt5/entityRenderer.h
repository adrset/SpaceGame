#pragma once
#include <map>
#include <list>
#include <vector>
#include "staticShader.h"
namespace engineX {
	class entityRenderer
	{
	public:
		entityRenderer(staticShader& shader, glm::mat4 projectionMatrix);
		~entityRenderer();
		void render(std::map<texturedModel, std::list<entity>> entities);
	private: 
		staticShader m_shader;

		void prepareTexturedModel(texturedModel model);
		void unbindTexturedModel();
		void prepareInstance(entity ent);
	};


}