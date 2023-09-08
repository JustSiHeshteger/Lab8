#pragma once
#include <string>
#include <vector>
#include <map>

class Translite
{
private:
    int size = 66;
    std::string rus[66] = { "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�",
                            "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", 
                            "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�",
                            "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�",
                            "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�",
                            "�", "�", "�", "�", "�", "�", "�", "�", "�", "�", "�" };

    std::string eng[66] = { "A", "B", "V", "G", "D", "Ye", "Yo", "Zh", "Z", "I", "J",
                            "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "F",
                            "H", "C", "Ch", "Sh", "Shh", "''", "Y", "'", "E", "Yu", "Ya",
                            "a", "b", "v", "g", "d", "ye", "yo", "zh", "z", "i", "j",
                            "k", "l", "m", "n", "o", "p", "r", "s", "t", "u", "f",
                            "h", "c", "ch", "sh", "shh", "''", "y", "'", "e", "yu", "ya" };

public:
    std::vector<std::pair<std::string, std::string>> translite(std::string content);
    std::vector<std::pair<std::string, std::string>> translite(std::vector<std::string> content);
};

