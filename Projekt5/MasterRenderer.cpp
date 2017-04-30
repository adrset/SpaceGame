#include "MasterRenderer.h"
#include "utils.h"
#include "game.h"

namespace engineX {


	float MasterRenderer::FOV = 80.0f;
	float MasterRenderer::NEAR_PLANE = 0.1f;
	const float MasterRenderer::FAR_PLANE = 90000000.0f;
	float MasterRenderer::RED = 0.2f;
	float MasterRenderer::GREEN = 0.2f;
	float MasterRenderer::BLUE = 0.5f;

	MasterRenderer::MasterRenderer(loader loader/*, sceneLoader sceneLoader*/)
	{
		createProjectionMatrix();
		enableCulling();
		m_entityRenderer = new entityRenderer(m_shader, m_projectionMatrix);
		//terrainRenderer = new terrainRenderer(terrainShader, projectionMatrix);
		//skyboxRenderer = new skyboxRenderer(loader, projectionMatrix, sceneLoader.getSkyboxTextureNames());
	}

	void MasterRenderer::createProjectionMatrix() {
		float aspectRatio = (float)game::st_width / (float)game::st_height;
		float y_scale = (float)((1.0f / tan(utils::toRadians(FOV / 2.0f))) * aspectRatio);
		float x_scale = y_scale / aspectRatio;
		float frustum_length = FAR_PLANE - NEAR_PLANE;


		//projection matrix definiton
		m_projectionMatrix;
		m_projectionMatrix[0][0] = (x_scale);
		m_projectionMatrix[1][1] = (y_scale);
		m_projectionMatrix[2][2] = (-((FAR_PLANE + NEAR_PLANE) / frustum_length));
		m_projectionMatrix[2][3] = (-1);
		m_projectionMatrix[3][2] = (-((2 * NEAR_PLANE * FAR_PLANE) / frustum_length));
		m_projectionMatrix[3][3] = (0);
	}

	MasterRenderer::~MasterRenderer()
	{
	}

	void MasterRenderer::render(std::vector<light> lights, camera3d camera) {
		prepare();
		m_shader.start();
		m_shader.loadLights(lights);
		m_shader.loadSkyColor(RED, GREEN, BLUE);
		m_shader.loadViewMatrix(camera);
		m_entityRenderer->render(m_entities);
		m_shader.stop();
		m_entities.clear();

		/*terrainShader.start();
		terrainShader.loadSkyColor(RED, GREEN, BLUE);
		terrainShader.loadLights(lights);
		terrainShader.loadViewMatrix(camera);
		terrainRenderer.render(terrains);
		terrainShader.stop();
		terrains.clear();
		skyboxRenderer.render(camera);*/

	}

	void MasterRenderer::cleanUp() {
		m_shader.cleanUp();
	//	terrainShader.cleanUp();
	}

	void MasterRenderer::prepare() {

		glfwPollEvents();
		glEnable(GL_DEPTH_TEST);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(RED, GREEN, BLUE, 1.0f);

	}

	void MasterRenderer::render(camera camera) {
		prepare();
	}


	void MasterRenderer::proccessEntity(entity ent) {

		texturedModel entityModel = ent.getModel();
		std::map<texturedModel,std::list<entity>>::iterator it;
		it = m_entities.find(entityModel);
		if (it != m_entities.end()) {
			m_entities.at(entityModel).push_back(ent);
		}else {
			std::list<entity> newFellowEntites;
			newFellowEntites.push_back(ent);
			m_entities.insert(std::make_pair(entityModel, newFellowEntites));
		}
	}

	void MasterRenderer::enableCulling() {
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
	}
	void MasterRenderer::disableCulling() {
		glDisable(GL_CULL_FACE);
	}
}