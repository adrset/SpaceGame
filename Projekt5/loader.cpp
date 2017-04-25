#include "loader.h"
#include "texture.h"

namespace engineX {
	loader::loader()
	{
	}


	loader::~loader()
	{
	}

	int loader::loadToVAO(float positions[], float textureCoords[]) {
		int vaoID = createVAO();
		storeDataInAttribList(0, 2, positions); //2d!
		storeDataInAttribList(1, 2, textureCoords);
		unbindVAO();
		return vaoID;
	}

	rawModel loader::loadToVAO(float positions[], float textureCoords[], float normals[], int indices[]) {
		int vaoID = createVAO();
		bindIndicesBuffer(indices);
		storeDataInAttribList(0, 3, positions);
		storeDataInAttribList(1, 2, textureCoords);
		storeDataInAttribList(2, 3, normals);
		unbindVAO();
		return rawModel(vaoID, sizeof(indices)/(sizeof(int)));
	}

	rawModel loader::loadToVAO(float positions[], int dim) {
		int vaoID = createVAO();
		storeDataInAttribList(0, dim, positions);
		unbindVAO();
		return rawModel(vaoID, (sizeof(positions)/(sizeof(float))) / dim);
	}

	int loader::loadTexture(std::string fileName) {
		texture *txt = new texture(fileName);
		int textureID = txt->getID();

		//enable mipmaping
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		textures.push_back(textureID);
		return textureID;

	}

	int loader::loadCubeMap(std::string textures[]) {
	/*	int texID = glGenTextures();
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, texID);
		for (int i = 0; i<sizeof(textures)/sizeof(std::string); i++) {
			TextureInByteBuffer data = decodeTextureFile(textures[i]);
			//Param 1 -> 1 of 6 
			GL11.glTexImage2D(GL13.GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL11.GL_RGBA, data.getWidth(), data.getHeight(), 0, GL11.GL_RGBA, GL11.GL_UNSIGNED_BYTE, data.getBuffer());
		}
		//To make it smooth
		GL11.glTexParameteri(GL13.GL_TEXTURE_CUBE_MAP, GL11.GL_TEXTURE_MAG_FILTER, GL11.GL_LINEAR);
		GL11.glTexParameteri(GL13.GL_TEXTURE_CUBE_MAP, GL11.GL_TEXTURE_MIN_FILTER, GL11.GL_LINEAR);

		//say no to lines on the edges!
		GL11.glTexParameteri(GL13.GL_TEXTURE_CUBE_MAP, GL11.GL_TEXTURE_WRAP_S, GL12.GL_CLAMP_TO_EDGE);
		GL11.glTexParameteri(GL13.GL_TEXTURE_CUBE_MAP, GL11.GL_TEXTURE_WRAP_T, GL12.GL_CLAMP_TO_EDGE);
		this.textures.add(texID);
		return texID;*/
		return 1;
	}

	//duplicate, in future the method from texture class will be used
	/*TextureInByteBuffer loader::decodeTextureFile(String fileName) {
		int width = 0;
		int height = 0;
		ByteBuffer buffer = null;
		try {
			InputStream in = Class.class.getResourceAsStream("/res/textures/" + fileName + ".png");
			PNGDecoder decoder = new PNGDecoder(in);
			width = decoder.getWidth();
			height = decoder.getHeight();
			buffer = ByteBuffer.allocateDirect(4 * width * height);
			decoder.decode(buffer, width * 4, Format.RGBA);
			buffer.flip();
			in.close();
		}
		catch (Exception e) {
			e.printStackTrace();
			System.err.println("Tried to load texture " + fileName + ", didn't work");
			System.exit(-1);
		}
		return new TextureInByteBuffer(buffer, width, height);
	}*/

	int loader::createVAO() {
		/*int vaoID = glGenVertexArrays();
		vaos.push_back(vaoID);
		glBindVertexArray(vaoID);
		return vaoID;*/
		return 0;
	}

	void loader::cleanUp() {

		/*for (int vao : vaos) {
			glDeleteVertexArrays(sizeof(vaos),vaos);
		}

		for (int vbo : vbos) {
			glDeleteBuffers(vbo);
		}
		for (int texture : textures) {
			glDeleteTextures(texture);
		}*/
	}

	void loader::storeDataInAttribList(int attribNumber, int size, float data[]) {
	/*	int vboID = glGenBuffers();
		vbos.add(vboID);
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, vboID);
		FloatBuffer buffer = storeDataInFB(data);
		GL15.glBufferData(GL15.GL_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW); // static means I will not edit the data when it is stored in buffer
		GL20.glVertexAttribPointer(attribNumber, size, GL11.GL_FLOAT, false, 0, 0);
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0); // Unbind the vbo*/
	}

	void loader::unbindVAO() {
		glBindVertexArray(0);

	}

	void loader::bindIndicesBuffer(int indices[]) {
		/*int vboID = glGenBuffers();
		vbos.push_back(vboID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);*/
		/*IntBuffer buffer = storeDataInIntBuffer(indices);
		GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);*/
	}
}