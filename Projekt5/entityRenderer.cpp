#include "entityRenderer.h"
#include "MasterRenderer.h"
#include "utils.h"

namespace engineX {


	entityRenderer::entityRenderer(staticShader& shader, glm::mat4 projectionMatrix)
	{
		this->m_shader = shader;
		shader.start();
		shader.loadProjectionMatrix(projectionMatrix);
		shader.stop();
	}


	void entityRenderer::render(std::map<texturedModel, std::list<entity>> entities) {
		for (auto const& x : entities)
		{
			prepareTexturedModel(x.first);
			for (auto const& y : x.second) {
				prepareInstance(y);
				glDrawElements(GL_TRIANGLES, x.first.getVertexCount(), GL_UNSIGNED_INT, 0);
			}
			unbindTexturedModel();
		}
	}

	void entityRenderer::prepareTexturedModel(texturedModel model) {

		glBindVertexArray(model.getVaoID());
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);


		//disable culling for transparent objects
		if (model.getModelTexture().isHasTransparency()) {
			MasterRenderer::disableCulling();
		}
		m_shader.loadFakeLight(model.getModelTexture().isFakeLight());
		m_shader.loadShineVariables(model.getModelTexture().getShineDamper(), model.getModelTexture().getReflect());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, model.getModelTexture().getTextureID());

	}

	void entityRenderer::unbindTexturedModel() {
		MasterRenderer::enableCulling();
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);
		glBindVertexArray(0);
	}
	void entityRenderer::prepareInstance(entity ent) {
		glm::mat4 transformationMatrix = utils::createTransformationMatrix(ent.getPosition(),
			ent.getRotationX(), ent.getRotationY(), ent.getRotationZ(), ent.getScale());
		m_shader.loadTransformationMatrix(transformationMatrix);
	}

	entityRenderer::~entityRenderer()
	{
	}
}