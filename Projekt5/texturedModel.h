#pragma once
#include "rawModel.h"
#include "modelTexture.h"
namespace engineX {
	class texturedModel : public rawModel
	{
	public:
		//Creating copy constructor requires creating own default constructor
		texturedModel() {};
		texturedModel(rawModel model, modelTexture texture);
		~texturedModel();
		modelTexture getModelTexture() const {return m_texture;	}
	private: 
		modelTexture m_texture;
	};

}