#pragma once
#include <string>
#include <glm/vec3.hpp>
#include "texturedModel.h"
#include "entity.h"

namespace engineX {
	class planet : entity
	{
	public:
		planet();
		planet(texturedModel model, glm::vec3 rotation, float startAngle, float mass, float radius, float majorAxis, float minorAxis, float angularVelocity);
		planet(entity a, float mass, float radius, float majorAxis, float minorAxis);
		~planet();

		float getMass() const { return m_mass;}

		std::string getName() const {return m_name;}
		float getStartAngle()const {return m_startAngle;}
		float getCurrentAngle() const {return m_currentAngle;}
		float getRadius() const {return m_radius;}
		float getMajorAxis() const {return m_majorAxis;}
		float getMinorAxis() const {return m_minorAxis;}

		void setMass(float mass);
		void setStartAngle(float angle);
		void setCurrentAngle(float angle);
		void setName(std::string name);
		void setRadius(float radius);
		void setMajorAxis(float majorAxis);
		void setMinorAxis(float minorAxis);
		void move();
	private:
		static float MAX_PLANET_RADIUS;
		float m_mass;
		float m_radius;
		float m_majorAxis;
		float m_minorAxis;
		float m_startAngle;
		float m_currentAngle;
		float m_angularVelocity;
		std::string m_name;	
	};

}