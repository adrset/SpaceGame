#include "camera.h"
namespace engineX {
	camera::camera()
	{
		position.x = 0;
		position.y = 0;
		position.z = 0;
	}
	camera::~camera()
	{
	}

	void camera::setPitch(float pitch) {
		this->pitch = pitch;
	}

	void camera::setYaw(float yaw) {
		this->yaw = yaw;
	}

	void camera::setRoll(float roll) {
		this->roll = roll;
	}
	void camera::setPosition(glm::vec3 newPosition) {
		this->position = newPosition;
	}
}