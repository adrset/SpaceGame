#include "timer.h"
namespace engineX {


	timer::timer()
	{
	}


	timer::~timer()
	{
	}

	std::chrono::steady_clock::time_point timer::startTime;
	std::chrono::steady_clock::time_point timer::currentTime;
	double timer::lastLoopTime;

	double timer::currentFakeTime;
	double timer::fps;
	double timer::trueFps;
	double timer::maxFPS;

	void timer::init(float targetFPS) {
		setMaxFPS(targetFPS);
		currentFakeTime = 0;
	}

	void timer::setMaxFPS(float targetFPS) {
		maxFPS = targetFPS;
	}
	void timer::begin() {
		startTime = getCurrentTime();
	}
	
	std::chrono::steady_clock::time_point timer::getCurrentTime() {
		return std::chrono::high_resolution_clock::now();
	}

	float timer::end() {
		//calculateFPS();
		currentTime = getCurrentTime();
		std::chrono::duration<double> duration = currentTime - startTime;
		double frameTime = duration.count();
		trueFps = 1 / frameTime;

		if (frameTime < 1 / maxFPS) {
			fps = maxFPS;
			lastLoopTime = 1 / fps;
			currentFakeTime += lastLoopTime;
			return (float)(1 / maxFPS - frameTime);

		}
		else {
			fps = 1 / frameTime;
			lastLoopTime = frameTime;
			currentFakeTime += lastLoopTime;
			return 0;
		}

	}
}