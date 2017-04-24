#pragma once
#include <vector>
//static class - we need only one IO manager
namespace engineX {
	class IO
	{
	public:
		static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
		static bool readFileToVector(std::string filePath, std::vector<std::string>& buffer);
	};

}
