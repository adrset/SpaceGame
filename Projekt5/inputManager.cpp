#include "inputManager.h"

namespace engineX {

	inputManager::inputManager() :m_mouseCoords(0) {

	}

	inputManager::~inputManager() {

	}
	void inputManager::update() {

		for (auto& it : m_keyMap) {
			m_previousKeyMap[it.first] = it.second;
		}
		for (auto& it : m_mouseKeyMap) {
			m_previousMouseKeyMap[it.first] = it.second;
		}
	}

	void inputManager::pressKey(unsigned int keyID) {
		m_keyMap[keyID] = true; // same as _keyMap.insert();
	}
	void inputManager::releaseKey(unsigned int keyID) {
		m_keyMap[keyID] = false;
	}

	void inputManager::setMouseCoords(float x, float y) {
		m_mouseCoords.x = x;
		m_mouseCoords.y = y;
	}
	bool inputManager::isKeyDown(unsigned int keyID) {
		auto it = m_keyMap.find(keyID);
		if (it != m_keyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	bool inputManager::isKeyPressed(unsigned int keyID)
	{
		bool isPressed = false;
		if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}


	bool inputManager::wasKeyDown(unsigned int keyID)
	{
		auto it = m_previousKeyMap.find(keyID);
		if (it != m_previousKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}
	

	void inputManager::pressMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = true;
	}

	void inputManager::releaseMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = false;
	}

	bool inputManager::isMouseKeyDown(unsigned int keyID) {
		auto it = m_mouseKeyMap.find(keyID);
		if (it != m_mouseKeyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	bool inputManager::isMouseKeyPressed(unsigned int keyID)
	{
		bool isPressed = false;
		if (isMouseKeyDown(keyID) == true && wasMouseKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}

	bool inputManager::wasMouseKeyDown(unsigned int keyID)
	{
		auto it = m_previousMouseKeyMap.find(keyID);
		if (it != m_previousMouseKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}

}