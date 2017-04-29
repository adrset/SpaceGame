#pragma once
#include "camera.h"
#include "player.h"
namespace engineX {
	class camera3d : public camera
	{
	public:
		camera3d(player p);
		~camera3d();
		void move();
	private:
		float m_distanceFromPlayer = 50;
		float m_angleAroundPlayer = 0;
		player m_player;

		void calculateCameraPosition(float hDistance, float vDistance);

		void calculateZoom();

		float calculateHorizontalDistance();

		float calculateVerticalDistance();

		void calculatePitch();

		void calculateAngle();
	};
}

