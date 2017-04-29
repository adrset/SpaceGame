#include "planet.h"
#include "timer.h"
#include "utils.h"
namespace engineX {

	float planet::MAX_PLANET_RADIUS = 1000;
	planet::planet()
	{
	}
	planet::planet(texturedModel model, glm::vec3 rotation, float startAngle, float mass, float radius, float majorAxis, float minorAxis, float angularVelocity) : entity(model, rotation, rotation.x, rotation.y, rotation.z, radius/MAX_PLANET_RADIUS )
	{
		this->m_angularVelocity = angularVelocity;
		this->m_startAngle = startAngle;
		this->m_mass = mass;
		this->m_radius = radius;
		this->m_majorAxis = majorAxis;
		this->m_minorAxis = minorAxis;
		this->m_currentAngle = startAngle;
	}
	planet::planet(entity a, float mass, float radius, float majorAxis, float minorAxis) :entity(a) {
		this->m_mass = mass;
		this->m_radius = radius;
		this->m_majorAxis = majorAxis;
		this->m_minorAxis = minorAxis;
	}


	planet::~planet()
	{
	}

	void planet::setMass(float mass) {
		this->m_mass = mass;
	}

	void planet::setStartAngle(float angle) {
		this->m_startAngle = angle;
	}

	void planet::setCurrentAngle(float angle) {
		this->m_currentAngle = angle;
	}

	void planet::setName(std::string name) {
		this->m_name = name;
	}

	void planet::setRadius(float radius) {
		this->m_radius = radius;
	}

	void planet::setMajorAxis(float majorAxis) {
		this->m_majorAxis = majorAxis;
	}

	void planet::setMinorAxis(float minorAxis) {
		this->m_minorAxis = minorAxis;
	}

	void planet::move() {
		//could be broken
		this->m_currentAngle = this->m_startAngle + (float)(m_angularVelocity *timer::getCurrentFakeTime());
		setPosition(glm::vec3((float)(m_majorAxis * cos(utils::toRadians(this->m_currentAngle))), 0.0f,
			(float)(m_minorAxis * sin(utils::toRadians(this->m_currentAngle)))));
	}
}