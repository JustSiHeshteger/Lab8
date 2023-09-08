#include "Translite.h"

std::vector<std::pair<std::string, std::string>> Translite::translite(std::string content) {
	std::string trWord;
	std::string ruWord;
	std::vector<std::pair<std::string, std::string>> words;

	for (size_t i = 0; i < content.size(); i++) {
		bool flag = false;
		std::string buf;
		buf += content[i];
		for (int j = 0; j < this->size; j++) {
			if (buf.compare(rus[j]) == 0) {
				trWord += this->eng[j];
				ruWord += rus[j];
				flag = true;
				break;
			}
		}

		if (!flag && trWord != "") {
			words.push_back(std::make_pair(ruWord, trWord));
			trWord.clear();
			ruWord.clear();
		}
		else if (i == content.size() - 1 && flag && trWord != "") {
			words.push_back(std::make_pair(ruWord, trWord));
		}
	}

	return words;
}

std::vector<std::pair<std::string, std::string>> Translite::translite(std::vector<std::string> content) {
	std::string trWord;
	std::string ruWord;
	std::vector<std::pair<std::string, std::string>> words;
	for (size_t a = 0; a < content.size(); a++) {
		std::string bufString = content[a];
		for (size_t i = 0; i < bufString.size(); i++) {
			bool flag = false;
			std::string buf = "";
			buf += bufString[i];
			for (int j = 0; j < this->size; j++) {
				if (buf.compare(rus[j]) == 0) {
					trWord += this->eng[j];
					ruWord += rus[j];
					flag = true;
					break;
				}
			}

			if (!flag && trWord != "") {
				words.push_back(std::make_pair(ruWord, trWord));
				trWord.clear();
				ruWord.clear();
			}
			else if (i == bufString.size() - 1 && flag && trWord != "") {
				words.push_back(std::make_pair(ruWord, trWord));
			}
		}
	}
	

	return words;
}