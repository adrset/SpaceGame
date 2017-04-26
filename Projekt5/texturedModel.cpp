#include "texturedModel.h"

namespace engineX {

	texturedModel::texturedModel(rawModel model, modelTexture texture) : rawModel(model), m_texture(texture)
	{
	}


	texturedModel::~texturedModel()
	{
	}
}