#pragma once
#include <glm/vec3.hpp>
#include "texturedModel.h"
namespace engineX {
	class entity
	{
	public:
		friend class MasterRenderer;
		~entity();
		entity() {}
		entity(const entity& a);
		void setModel(texturedModel model);
		entity(texturedModel model, glm::vec3 position, float rotationX, float rotationY, float rotationZ, float scale);
		void setPosition(glm::vec3 position);
		void setRotationX(float rotationX);
		void setRotationY(float rotationY);
		void setRotationZ(float rotationZ);
		void setScale(float scale);

		texturedModel getModel() { return this->m_model; }
		float getRotationZ() { return m_rotationZ; }
		float getScale() { return m_scale; }
		float getRotationY() { return m_rotationY; }
		glm::vec3 getPosition() { return m_position; }
		float getRotationX() { return m_rotationX; }

		void increasePosition(float dx, float dy, float dz);
		void increaseRotation(float rx, float ry, float rz);
	private:
		glm::vec3 m_position;
		float m_rotationX, m_rotationY, m_rotationZ;
		float m_scale;
		texturedModel m_model;
		
	};

}

