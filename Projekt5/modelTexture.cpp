#include "modelTexture.h"

namespace engineX{

modelTexture::modelTexture(int id) : m_textureID(id)
{
}


modelTexture::~modelTexture()
{
}

void modelTexture::setFakeLight(bool fakeLight) {
	this->m_fakeLight = fakeLight;
}
void modelTexture::setHasTransparency(bool trans) {
	m_hasTransparency = trans;
}


void modelTexture::setTextureID(int textureID) {
	this->m_textureID = textureID;
}


void modelTexture::setShineDamper(float shineDamper) {
	this->m_shineDamper = shineDamper;
}


void modelTexture::setReflect(float reflect) {
	this->m_reflect = reflect;
}

}
