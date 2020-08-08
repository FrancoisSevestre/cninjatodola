#ifndef VARIOUSFUNCTIONS_H
#define VARIOUSFUNCTIONS_H
#include <string>
#include <vector>

std::string singleCharacterInput();
std::vector<std::string> cutString(std::string toBeCut, std::string separator, bool getLast = false);
bool fileExists(const std::string path);
bool dirExists(const std::string path);
std::vector<std::string> listDirectoriesInDirectory(const std::string path);
std::vector<std::string> listFilesInDirectory(const std::string path);

std::vector<std::string> fileToStringVector(std::string path);

#endif // VARIOUSFUNCTIONS_H
