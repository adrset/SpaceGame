#include "MasterRenderer.h"



MasterRenderer::MasterRenderer()
{
}


MasterRenderer::~MasterRenderer()
{
}


void MasterRenderer::enableCulling() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
}
void MasterRenderer::disableCulling() {
	glDisable(GL_CULL_FACE);
}
