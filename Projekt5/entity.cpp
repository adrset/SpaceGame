#include "entity.h"


namespace engineX {


	entity::~entity()
	{
	}

	entity::entity(const entity& a) {
		this->m_position = a.m_position;
		this->m_rotationX = a.m_rotationX;
		this->m_rotationY = a.m_rotationY;
		this->m_rotationZ = a.m_rotationZ;
		this->m_model = a.m_model;
		this->m_scale = a.m_scale;
	}

	entity::entity(texturedModel model, glm::vec3 position, float rotationX, float rotationY, float rotationZ, float scale){
		this->m_model = model;
		this->m_position = position;
		this->m_rotationX = rotationX;
		this->m_rotationY = rotationY;
		this->m_rotationZ = rotationZ;
		this->m_scale = scale;
	}

	void entity::setModel(texturedModel model) {
		this->m_model = model;
	}

	void entity::setPosition(glm::vec3 position) {
		this->m_position = position;
	}

	void entity::setRotationX(float rotationX) {
		this->m_rotationX = rotationX;
	}

	void entity::setRotationY(float rotationY) {
		this->m_rotationY = rotationY;
	}


	void entity::setRotationZ(float rotationZ) {
		this->m_rotationZ = rotationZ;
	}

	void entity::setScale(float scale) {
		this->m_scale = scale;
	}

	 void entity::increasePosition(float dx, float dy, float dz) {
		this->m_position.x += dx;
		this->m_position.y += dy;
		this->m_position.z += dz;
	}
	void entity::increaseRotation(float rx, float ry, float rz) {
		this->m_rotationX += rx;
		this->m_rotationY += ry;
		this->m_rotationZ += rz;
	}

}