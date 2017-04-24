#include <fstream>
#include <vector>
#include "shaderProgram.h"

namespace engineX {
	shaderProgram::shaderProgram(std::string vertexFile, std::string fragmentFile) : m_vertexShaderID(loadShader(vertexFile, GL_VERTEX_SHADER)),
		m_fragmentShaderID(loadShader(fragmentFile, GL_FRAGMENT_SHADER)), m_programID(glCreateProgram())
	{
		
	}

	shaderProgram::~shaderProgram()
	{
	}
	

	void shaderProgram::init() {
		glAttachShader(m_programID, m_vertexShaderID);
		glAttachShader(m_programID, m_fragmentShaderID);
		bindAttributes();
		glLinkProgram(m_programID);
		glValidateProgram(m_programID);
		getAllUniformLocations();
	}

	int shaderProgram::getUniformLocation(std::string uniformName) {
		return glGetUniformLocation(m_programID, uniformName.c_str());
	}

	void shaderProgram::start() {
		glUseProgram(m_programID);
	}

	void shaderProgram::stop() {
		glUseProgram(0);
	}

	void shaderProgram::cleanUp() {
		stop();
		glDetachShader(m_programID, m_vertexShaderID);
		glDetachShader(m_programID, m_fragmentShaderID);
		glDeleteShader(m_vertexShaderID);
		glDeleteShader(m_fragmentShaderID);
		glDeleteProgram(m_programID);
	}

	void shaderProgram::bindAttribute(int attribute, std::string variableName) {
		glBindAttribLocation(m_programID, attribute, variableName.c_str());
	}

	void shaderProgram::loadFloat(int location, float value) {
		glUniform1f(location, value);
	}

	void shaderProgram::loadVector(int location, glm::vec3 vector) {
		glUniform3f(location, vector.x, vector.y, vector.z);
	}

	void shaderProgram::loadVector2D(int location, glm::vec2 vector) {
		glUniform2f(location, vector.x, vector.y);
	}

	void shaderProgram::loadBoolean(int location, bool value) {
		float toLoad = 0;
		if (value) {
			toLoad = 1;
		}
		glUniform1f(location, toLoad);
	}

	void shaderProgram::loadMatrix(int location, glm::mat4 matrix) {
		glUniformMatrix4fv(location, false, false, glm::value_ptr(matrix)); // not transposed
	}

	int shaderProgram::loadShader(std::string file, int type) {
		std::ifstream vertFile(file);
		if (vertFile.fail()) {
			fatalError("Failed to open " + file);
		}
		std::string fileContents = "";
		std::string line;
		while (std::getline(vertFile, line)) {
			fileContents += line + "\n";
		}

		vertFile.close();
		const char* contentsPtr = fileContents.c_str();
		

		int shaderID = glCreateShader(type);
		glShaderSource(shaderID, 1, &contentsPtr, nullptr);

		glCompileShader(shaderID);

		GLint success = 0;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

		if (success = GL_FALSE) {
			GLint maxLength;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> errorLog(maxLength);
			glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

			glDeleteShader(shaderID);
			std::printf("%s\n", &(errorLog[0]));
			fatalError("Shader " + file + " failed to compile.");

		}

		return shaderID;

	}

}