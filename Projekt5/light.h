#pragma once
#include <glm/vec3.hpp>
namespace engineX {
	class light
	{
	public:
		light(glm::vec3 pos, glm::vec3 color, glm::vec3 att);
		light(glm::vec3 pos, glm::vec3 color);
		~light();
	
		void setPosition(glm::vec3 position);
		void setColor(glm::vec3 color);
		glm::vec3 getAttenuation() const { return m_attenuation; }
		glm::vec3 getPosition() const {return m_position;}
		glm::vec3 getColor() const {return m_color;}
	private:
		glm::vec3 m_position;
		glm::vec3 m_color;
		glm::vec3 m_attenuation = glm::vec3(1, 0, 0); //infinite distance light

	
	};

}