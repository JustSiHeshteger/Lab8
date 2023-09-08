#include "FileManager.h"

bool FileManager::checkFileStat(std::string path) {
	std::ifstream inputFile;
	inputFile.open(path);
	struct stat buf;

	if (!inputFile || (stat(path.c_str(), &buf) != 0)) {
		inputFile.close();
		return false;
	}
	else {
		inputFile.close();
		return true;
	}
}

std::string FileManager::getFileData(std::string path) {
	std::ifstream inputFile;
	std::string content;
	std::string buf;

	inputFile.open(path);

	while (std::getline(inputFile, buf)) {
		content += buf + '\n';
	}

	inputFile.close();
	return content;
}