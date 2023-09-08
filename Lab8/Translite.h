#pragma once
#include <string>
#include <vector>
#include <map>

class Translite
{
private:
    int size = 66;
    std::string rus[66] = { "À", "Á", "Â", "Ã", "Ä", "Å", "¨", "Æ", "Ç", "È", "É",
                            "Ê", "Ë", "Ì", "Í", "Î", "Ï", "Ð", "Ñ", "Ò", "Ó", "Ô", 
                            "Õ", "Ö", "×", "Ø", "Ù", "Ú", "Û", "Ü", "Ý", "Þ", "ß",
                            "à", "á", "â", "ã", "ä", "å", "¸", "æ", "ç", "è", "é",
                            "ê", "ë", "ì", "í", "î", "ï", "ð", "ñ", "ò", "ó", "ô",
                            "õ", "ö", "÷", "ø", "ù", "ú", "û", "ü", "ý", "þ", "ÿ" };

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

