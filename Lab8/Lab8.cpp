#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <map>
#include <set>

#include "FileManager.h"
#include "Translite.h"
#include "Validator.h"
#include "Search.h"

std::string getString(std::string);
int getNumber(std::string);
int getMaxLength(std::vector<std::pair<std::string, std::string>>);
void findCoincidencesCollisions(std::vector<std::pair<std::string, std::string>>);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    FileManager fileManager;
    Translite translite;
    Search search;

    std::string content;
    std::string path;

    std::cout << "Выберите действие:\n"
              << "1. Указать файл\n"
              << "2. Выход\n" << std::endl;

    int action;
    do {
        action = getNumber("Введите число (ЦЕЛОЕ, ПОЛОЖИТЕЛЬНОЕ, более 0): ");
    } while (!Validator::checkNumber(action));

    switch (action)
    {
    case 1:
        do {
            path = getString("Введите путь: ");
        } while (!fileManager.checkFileStat(path));

        content = fileManager.getFileData(path);
        break;

    case 2:
        return 0;
        break;

    default:
        break;
    }

    std::vector<std::pair<std::string, std::string>> wordsTranslite = translite.translite(content);

    std::cout << "Список слов транслитом: " << std::endl;
    std::vector<std::pair<std::string, std::string>>::iterator it = wordsTranslite.begin();
    std::vector<std::string> hash;
    std::vector<std::string> word;
    int length = getMaxLength(wordsTranslite);
    for (; it != wordsTranslite.end(); it++) {
        std::cout << std::setw(length) << it->first << " | " << std::setw(length) << it->second << std::endl;
        hash.push_back(it->second);
        word.push_back(it->first);
    }

    std::cout << std::endl;

    findCoincidencesCollisions(wordsTranslite);

    std::cout << std::endl;

    do {
        action = getNumber("Выберите действие:\n1. Поиск по транслиту\n2. Выход\n\n");
    } while (!Validator::checkNumber(action));

    std::set<std::string> result;

    switch (action)
    {
    case 1:
        {
        std::cout << "Введите транслит: ";
        std::string element;
        std::cin >> element;

        result = search.simpleSearch(wordsTranslite, element);
        }
        break;

    case 2:
        return 0;
        break;

    default:
        break;
    }

    if (result.size() == 0) {
        std::cout << "Элементов не найдено" << std::endl;
        return 0;
    }

    for (const std::string& word : result) {
        std::cout << word << std::endl;
    }
    return 0;
}

std::string getString(std::string message)
{
    std::string str = "";
    std::cout << message;
    std::getline(std::cin, str);
    return str;
}

int getNumber(std::string message)
{
    std::string number = "";

    do
    {
        std::cout << message;
        std::getline(std::cin, number);
    } while (!Validator::isIntegerNumber(number, "Введенное значение не является допустимым числом."));

    int num = std::stoi(number);
    return num;
}

int getMaxLength(std::vector<std::pair<std::string, std::string>> words) {
    std::vector<std::pair<std::string, std::string>>::iterator it = words.begin();
    size_t length = 0;

    for (; it != words.end(); it++) {
        if (it->first.length() > length) {
            length = it->first.length();
        }
    }

    return (int)length;
}

void findCoincidencesCollisions(std::vector<std::pair<std::string, std::string>> words) {
    std::map<std::string, int> wordCount;
    for (const auto& p : words) {
        const auto& word = p.first;
        wordCount[word]++;
    }
    int duplicateCount = 0;
    std::string duplicateString = "";
    for (const auto& pair : wordCount) {
        if (pair.second > 1) {
            duplicateString += " " + pair.first + ",";
            duplicateCount++;
        }
    }
    std::cout << "Количество повторяющихся слов: " << duplicateCount << std::endl;
    std::cout << "Слова: " << duplicateString << std::endl << std::endl;

    std::map<std::string, std::set<std::string>> hashToWords;
    for (const auto& p : words) {
        const auto& word = p.first;
        const auto& hash = p.second;
        hashToWords[hash].insert(word);
    }

    int sameHashCount = 0;
    std::string hashString = "";
    for (const auto& pair : hashToWords) {
        if (pair.second.size() > 1) {
            sameHashCount++;
        }
    }
    std::cout << "Количество коллизий: " << sameHashCount;

    for (const auto& pair : hashToWords) {
        if (pair.second.size() > 1) {
            const std::set<std::string>& wordSet = pair.second;
            std::cout << std::endl << "Хэш: " << pair.first << std::endl;
            std::cout << "Слова: ";
            for (const std::string& word : wordSet) {
                std::cout << word << ", ";
            }
        }
    }    
    std::cout << std::endl;
}
