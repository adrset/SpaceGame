#pragma once
#include <chrono>
namespace engineX {
	class timer
	{
	public:
		timer();
		~timer();


		static double getFps() { return fps; }
		static double getTrueFPS() { return trueFps; }
		static double getCurrentFakeTime() { return currentFakeTime; }

		static std::chrono::steady_clock::time_point getCurrentTime();
		static double getLastLoopTime() { return lastLoopTime; }

		static void init(float targetFPS);

		static void setMaxFPS(float targetFPS);
		static void begin();
		static float end();

	private:
		static std::chrono::steady_clock::time_point startTime;
		static std::chrono::steady_clock::time_point currentTime;
		static double lastLoopTime;

		static double currentFakeTime;
		static double fps;
		static double trueFps;
		static double maxFPS;

	};

}