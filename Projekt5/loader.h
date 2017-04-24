#pragma once
#include <vector>
#include "rawModel.h"
namespace engineX {
	class loader
	{
	public:
		loader();
		~loader();
		int loadToVAO(float positions[], float textureCoords[]);
		rawModel loadToVAO(float positions[], float textureCoords[], float normals[], int indices[]);
		rawModel loadToVAO(float positions[], int dim);
		int loadTexture(std::string fileName);
		void cleanUp();
		int loadCubeMap(std::string textures[]);
		/*VA0 [0] -> Positions VBO
		VAO [1] -> Texture Co-ords VBO*/
	private:
		std::vector<int> vaos;
		std::vector<int> vbos;
		std::vector<int> texture;
		int createVAO();
		void storeDataInAttribList(int attribNumber, int size, float data[]);
		void unbindVAO();

		void bindIndicesBuffer(int indices[]);
		

		/*private IntBuffer storeDataInIntBuffer(int[] data) {
			IntBuffer buffer = BufferUtils.createIntBuffer(data.length);
			buffer.put(data);
			buffer.flip();
			return buffer;
		}

		private FloatBuffer storeDataInFB(float[] data) {
			FloatBuffer buffer = BufferUtils.createFloatBuffer(data.length);
			buffer.put(data);
			buffer.flip();
			return buffer;
		}*/
	};

}