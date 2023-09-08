#include "Search.h"

std::set<std::string> Search::simpleSearch(std::vector<std::pair<std::string, std::string>> words, std::string find) {
	std::set<std::string> result;

	for (const auto& pair : words) {
		if (pair.second.compare(find) == 0) {
			result.insert(pair.first);
		}
	}

	return result;
}

std::map<int, std::string> Search::sequenceSearch(std::vector<std::string> words, std::vector<std::string> finds) {
	std::map<int, std::string> result;

	for (size_t i = 0; i < words.size(); i++) {
		for (size_t j = 0; j < finds.size(); j++) {
			if (words[i].compare(finds[j]) == 0) {
				result.insert(std::make_pair(i + 1, words[i]));
			}
		}
	}

	return result;
}
