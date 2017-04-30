#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <list>
#include "loader.h"
#include "staticShader.h"
#include "entityRenderer.h"
#include "camera3d.h"
namespace engineX {
	class MasterRenderer
	{

	private:
		static float FOV;
		static float NEAR_PLANE;
		const static float FAR_PLANE;
		static float RED;
		static float GREEN;
		static float BLUE;
		glm::mat4 m_projectionMatrix;
		staticShader m_shader;
		//terrainShader terrainShader = new TerrainShader();
		//SkyboxRenderer skyboxRenderer;

		entityRenderer* m_entityRenderer;
		//TerrainRenderer terrainRenderer;


		std::map<texturedModel, std::list<entity>> m_entities;
		//std::list<terrain> terrains;
		void createProjectionMatrix();

	public:
		static void enableCulling();
		static void disableCulling();
		MasterRenderer(loader loader/*, sceneLoader sceneLoader*/);
		~MasterRenderer();

		void render(std::vector<light> lights, camera3d camera);

		void render(camera camera);

		//void proccessTerrain(terrain terrain);
		void proccessEntity(entity entity);

		void prepare();

		void cleanUp();
	};

}