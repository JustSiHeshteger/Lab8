#pragma once
#include <vector>
#include <string>
#include <map>
#include <set>

class Search
{
public:
	std::set<std::string> simpleSearch(std::vector<std::pair<std::string, std::string>>, std::string);
	std::map<int, std::string> sequenceSearch(std::vector<std::string>, std::vector<std::string>);
};

