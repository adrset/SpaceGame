#pragma once
#include <glm/vec3.hpp>
namespace engineX {
	class camera
	{
	public:
		camera();
		~camera();
		void setPitch(float pitch);
		void setYaw(float yaw);
		void setRoll(float roll);
		void setPosition(glm::vec3 newPosition);
		glm::vec3 getPosition() const { return position; }
		float getYaw() const { return yaw; }
		float getPitch() const { return pitch; }
		float getRoll() const { return roll; }
	protected:
		glm::vec3 position;
		float pitch;
		float yaw;
		float roll;
	};
}
