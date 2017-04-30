#include "texturedModel.h"

namespace engineX {


	bool texturedModel::operator<(const texturedModel& rhs) const
	{
		return m_texture.getTextureID() < rhs.m_texture.getTextureID();
	}

	texturedModel::texturedModel(rawModel model, modelTexture texture) : rawModel(model), m_texture(texture)
	{
	}


	texturedModel::~texturedModel()
	{
	}
}