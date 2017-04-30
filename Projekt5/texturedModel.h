#pragma once
#include "rawModel.h"
#include "modelTexture.h"
namespace engineX {


	/*bool operator<(const modelTexture first, const modelTexture second);
	bool operator<(const modelTexture &first, const modelTexture &second);*/
	class texturedModel : public rawModel
	{
	public:
		bool operator <(const texturedModel& rhs) const;
		//Creating copy constructor requires creating own default constructor
		texturedModel() {};
		texturedModel(rawModel model, modelTexture texture);
		~texturedModel();
		modelTexture getModelTexture() {return m_texture;	}

	private: 
		modelTexture m_texture;
	};

}