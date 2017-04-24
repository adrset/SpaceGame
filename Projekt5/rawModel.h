#pragma once
namespace engineX {
	class rawModel
	{
	public:
		rawModel(int vaoID, int vertexCount);
		~rawModel();

		int getVaoID() const { return vaoID; }

		int getVertexCount() const { return vertexCount; }
	private:
		int vaoID;
		int vertexCount;


	};
}

