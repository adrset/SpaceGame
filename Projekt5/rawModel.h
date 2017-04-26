#pragma once
namespace engineX {
	class rawModel
	{
	public:
		//Creating copy constructor requires creating own default constructor
		rawModel() {};

		rawModel(int vaoID, int vertexCount);
		~rawModel();

		int getVaoID() const { return vaoID; }

		int getVertexCount() const { return vertexCount; }
	private:
		int vaoID;
		int vertexCount;


	};
}

