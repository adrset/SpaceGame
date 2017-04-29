#include <cmath>
#include "utils.h"


namespace engineX {

	const float utils::PI = 3.14159265359f;
	utils::utils()
	{
	}


	utils::~utils()
	{
	}

	float utils::toRadians(float degree) {
		return (degree * PI / 180.0f);
	}
}