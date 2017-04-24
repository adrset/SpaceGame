#pragma once
#include "shaderProgram.h"
#include <vector>
namespace engineX {
	class staticShader : public shaderProgram
	{
	private:
		static const int MAX_LIGHTS;
		int location_transformationMatrix;
		int location_projectionMatrix;
		int location_viewMatrix;
		int* location_lightPosition;
		int* location_lightColor;
		int* location_attenuation;
		int location_shineDamper;
		int location_reflectivity;
		int location_useFakeLight;
		int location_skyColor;
		
		static const std::string VERTEX_FILE;
		static const std::string FRAGMENT_FILE;

	protected:
		void bindAttributes();
		void getAllUniformLocations();

	public:
		void init();
		staticShader();
		~staticShader();
		void loadTransformationMatrix(glm::mat4 matrix);
		void loadSkyColor(float r, float g, float b);
		void loadFakeLight(bool use);
		void loadShineVariables(float damper, float reflectivity);
		void loadLights(std::vector/*<Light>*/<std::string> lights);

		void loadProjectionMatrix(glm::mat4 matrix);
		void loadViewMatrix(/*Camera3D*/ std::string camera);
	};

}