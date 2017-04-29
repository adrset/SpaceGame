#include "camera3d.h"
#include "utils.h"
namespace engineX {


	camera3d::~camera3d()
	{
	}

	camera3d::camera3d(player p) {
		m_player = p;
	}

	void camera3d::move() {
		calculateZoom();
		calculatePitch();
		calculateAngle();
		calculateCameraPosition(calculateHorizontalDistance(), calculateVerticalDistance());
	}

	void camera3d::calculateCameraPosition(float hDistance, float vDistance) {
		float theta = m_player.getRotationY() + m_angleAroundPlayer;
		float xOffset = (float)(hDistance * sin(utils::toRadians(theta)));
		float zOffset = (float)(hDistance * cos(utils::toRadians(theta)));
		position.x = m_player.getPosition().x - xOffset;
		position.z = m_player.getPosition().z - zOffset;
		position.y = m_player.getPosition().y + vDistance;
		yaw = 180 - (m_player.getRotationY() + m_angleAroundPlayer);
	}

	void camera3d::calculateZoom() {
	//	float zoom = MouseScroll.getOffsetY() * 0.1f;
		//m_distanceFromPlayer -= zoom;
	}

	float camera3d::calculateHorizontalDistance() {
		return (float)(m_distanceFromPlayer * cos(utils::toRadians(pitch)));
	}

	float camera3d::calculateVerticalDistance() {
		return (float)(m_distanceFromPlayer * sin(utils::toRadians(pitch)));
	}

	void camera3d::calculatePitch() {
	/*	if (Keyboard.isKeyDown(GLFW.GLFW_KEY_LEFT_ALT) || MouseButtons.getButtonState(2) == 1) {
			double dPitch = Mouse.mouseCursor.getDY() * 0.3;
			pitch -= (float)dPitch;
		}
		else {
			pitch = 0;
		}*/
	}

	void camera3d::calculateAngle() {
		/*if (Keyboard.isKeyDown(GLFW.GLFW_KEY_LEFT_ALT) || MouseButtons.getButtonState(2) == 1) {
			double dAngle = Mouse.mouseCursor.getDX() * 0.3;
			m_angleAroundPlayer -= (float)dAngle;
		}
		else {
			m_angleAroundPlayer = 0;
		}*/
	}

}