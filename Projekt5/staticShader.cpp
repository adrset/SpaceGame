#include "staticShader.h"
#include "utils.h"
namespace engineX {

	staticShader::staticShader() : shaderProgram(VERTEX_FILE, FRAGMENT_FILE)
	{
		init();
	}

	const int staticShader::MAX_LIGHTS = 3;

	const std::string staticShader::VERTEX_FILE = "shader.frag";
	const std::string staticShader::FRAGMENT_FILE = "shader.vert";

	staticShader::~staticShader()
	{
	}

	void staticShader::bindAttributes() {
		bindAttribute(0, "position");//bind variable from shader
		bindAttribute(1, "textureCoords");
		bindAttribute(2, "normal");
	}

	void staticShader::init() {
		shaderProgram::init();
	}

	void staticShader::getAllUniformLocations() {
		location_transformationMatrix = getUniformLocation("transformationMatrix");
		location_projectionMatrix = getUniformLocation("projectionMatrix");
		location_viewMatrix = getUniformLocation("viewMatrix");
		location_shineDamper = getUniformLocation("shineDamper");
		location_reflectivity = getUniformLocation("reflectivity");
		location_useFakeLight = getUniformLocation("useFakeLight");
		location_skyColor = getUniformLocation("skyColor");

		location_lightPosition = new int[MAX_LIGHTS];
		location_lightColor = new int[MAX_LIGHTS];
		location_attenuation = new int[MAX_LIGHTS];

		for (int i = 0; i<MAX_LIGHTS; i++) {
			location_lightPosition[i] = getUniformLocation("lightPosition[" + i + ']');
			location_lightColor[i] = getUniformLocation("lightColor[" + i + ']');
			location_attenuation[i] = getUniformLocation("attenuation[" + i + ']');
		}

	}

	void staticShader::loadTransformationMatrix(glm::mat4 matrix) {
		loadMatrix(location_transformationMatrix, matrix);

	}

	void staticShader::loadSkyColor(float r, float g, float b) {
		loadVector(location_skyColor, glm::vec3(r,g,b));
	}

	void staticShader::loadFakeLight(bool use) {
		loadBoolean(location_useFakeLight, use);
	}

	void staticShader::loadShineVariables(float damper, float reflectivity) {
		loadFloat(location_shineDamper, damper);
		loadFloat(location_reflectivity, reflectivity);
	}
	void staticShader::loadLights(std::vector<light> lights) {
		for (unsigned int i = 0; i<MAX_LIGHTS; i++) {
			if (i<lights.size()) {
				loadVector(location_lightPosition[i], lights[i].getPosition());
				loadVector(location_lightColor[i], lights[i].getColor());
				loadVector(location_attenuation[i], lights[i].getAttenuation());
			}
			else {
				loadVector(location_lightPosition[i],  glm::vec3(0, 0, 0));
				loadVector(location_lightColor[i],  glm::vec3(0, 0, 0));
				loadVector(location_attenuation[i],  glm::vec3(1, 0, 0));
			}

		}

	}

	void staticShader::loadProjectionMatrix(glm::mat4 matrix) {
		loadMatrix(location_projectionMatrix, matrix);
	}

	void staticShader::loadViewMatrix(camera3d camera) {
		glm::mat4 viewMatrix = utils::createViewMatrix(camera);
		loadMatrix(location_viewMatrix, viewMatrix);
	}


}