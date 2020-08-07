#include "variousfunctions.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

std::string singleCharacterInput()
{
  system("rm /tmp/userChoice 2> /dev/null"); // remove previous user choice
  system("read -N 1 -t 30 variable  && echo $variable > /tmp/userChoice"); // create a temp file
  std::ifstream tmpfile;
  std::string userChoice;
  tmpfile.open("/tmp/userChoice", std::ios::in);
  userChoice = tmpfile.get();
  return userChoice;

}

std::vector<std::string> cutString(std::string toBeCut, std::string separator, bool getLast)
{
  size_t pos(0);
  std::string strPart;
  std::vector<std::string> strVector;
  
  while((pos = toBeCut.find(separator)) != std::string::npos) //while a separator is found
  {
    strPart = toBeCut.substr(0, pos); //delimit part
    strVector.push_back(strPart); // add part to vector
    toBeCut.erase(0, pos + separator.length()); // erase part
  }
  if(getLast) //get the part after the last separator
  {
    strVector.push_back(toBeCut);
  }
  return strVector;

}

bool fileExists(const std::string name) 
{
    std::ifstream filef(name);
    return filef.good();
}