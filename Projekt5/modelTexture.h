#pragma once
namespace engineX {
	class modelTexture
	{
	public:
		//Creating copy constructor requires creating own default constructor
		modelTexture() {};
		modelTexture(int id);
		~modelTexture();

		bool isFakeLight() const {return m_fakeLight;}
		void setFakeLight(bool fakeLight);
		bool isHasTransparency() const {return m_hasTransparency;}
		void setHasTransparency(bool trans);
		int getTextureID() const { return m_textureID;}
		void setTextureID(int textureID);
		float getShineDamper() const { return m_shineDamper;}
		void setShineDamper(float shineDamper);
		float getReflect() const { return m_reflect;}
		void setReflect(float reflect);

		
	private:
		float m_reflect = 1;
		int m_textureID;
		float m_shineDamper = 1;
		bool m_hasTransparency = false;
		bool m_fakeLight = false;
	};

}
