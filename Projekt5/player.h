#pragma once
#include "entity.h"
namespace engineX {
	class player : public entity
	{
	public:
		player() {}
		player(texturedModel model, glm::vec3 position, glm::vec3 rotation, float scale);
		~player();
		float getSpeed() const {return m_currentSpeed;}
		void move();
		void checkInput();

	private:
		float m_currentSpeed = 0;
		float m_currentSpeedUp = 0;
		float m_currentSpeedRotateSpeed = 0;
		static const float m_RUN_SPEED;
		static const float m_MAX_SPEED;
		static const float m_ROTATE_SPEED;

	};


}