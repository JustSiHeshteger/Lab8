#pragma once
#include <string>
#include <fstream>

class FileManager
{
public:
	bool checkFileStat(std::string path);
	std::string getFileData(std::string path);
};

