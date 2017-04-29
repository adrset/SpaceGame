#include "light.h"

namespace engineX {

	light::light(glm::vec3 pos, glm::vec3 color, glm::vec3 att) :m_position(pos), m_color(color),m_attenuation(att){

	}
	light::light(glm::vec3 pos, glm::vec3 color) : m_position(pos), m_color(color) {

	}


	void light::setPosition(glm::vec3 position) {
		this->m_position = position;
	}
	void light::setColor(glm::vec3 color) {
		this->m_color = color;
	}

	light::~light()
	{
	}

}