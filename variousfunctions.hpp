#ifndef VARIOUSFUNCTIONS_H
#define VARIOUSFUNCTIONS_H
#include <string>
#include <vector>

std::string singleCharacterInput();
std::vector<std::string> cutString(std::string toBeCut, std::string separator, bool getLast = false);
bool fileExists(const std::string name);

#endif // VARIOUSFUNCTIONS_H
