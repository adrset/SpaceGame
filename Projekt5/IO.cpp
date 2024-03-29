#include "IO.h"
#include <string>
#include <fstream>

namespace engineX {

	bool IO::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}
		//seek to the end
		file.seekg(0, std::ios::end);

		//file size
		int fileSize = (int)file.tellg();
		file.seekg(0, std::ios::beg);

		fileSize -= (int)file.tellg(); // no header bytes

		buffer.resize(fileSize);

		file.read((char *)&buffer[0], fileSize);//1 argwill return char pointer
		file.close();
		return true;

	}
	bool IO::readFileToVector(std::string filePath, std::vector<std::string>& buffer) {
		std::ifstream file(filePath, std::ios::binary);
		if (file.fail()) {
			perror(filePath.c_str());
			return false;
		}
		std::string line;
		while (std::getline(file, line)) {
			buffer.push_back(line);
		}
	}

}