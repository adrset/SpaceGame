#include "player.h"
#include "timer.h"
#include "utils.h"
namespace engineX {


	const float player::m_RUN_SPEED = 20;
	const float player::m_MAX_SPEED = 35000;
	const float player::m_ROTATE_SPEED = 30;
	player::player(texturedModel model, glm::vec3 position, glm::vec3 rotation, float scale) : entity(model, position, rotation.x, rotation.y, rotation.z, scale)
	{

	}
	void player::checkInput(){
	}

	void player::move() {
		checkInput();
		increaseRotation(0, (float)(m_currentSpeedRotateSpeed * timer::getLastLoopTime()), 0);
		float distance = (float)(m_currentSpeed * timer::getLastLoopTime());
		float distanceUp = (float)(m_currentSpeedUp * timer::getLastLoopTime());
		float dx = (float)(distance * sin(utils::toRadians(getRotationY())) *  cos(utils::toRadians(getRotationX())));
		float dz = (float)(distance * cos(utils::toRadians(getRotationY())) * cos(utils::toRadians(getRotationX())));
		float dy = (float)(distanceUp + distance * sin(utils::toRadians(getRotationX())));
		increasePosition(dx, dy, dz);
	}

	player::~player()
	{
	}
}