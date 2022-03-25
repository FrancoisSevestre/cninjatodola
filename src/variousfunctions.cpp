#include "variousfunctions.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>

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

bool fileExists(const std::string path) 
{
    std::ifstream filef(path);
    return filef.good();
}

bool dirExists(const std::string path) 
{
  system(("ls " + path + " 2> /tmp/dirExists.tmp > /dev/null").c_str());
  std::ifstream ifs;
  ifs.open("/tmp/dirExists.tmp");
  std::string output;
  getline(ifs, output);
  if(output == "")
  {
    return true;
  }
  else
  {
    return false;
  }
}

std::vector<std::string> listDirectoriesInDirectory(const std::string path) // return a liste of path finishing with a '/'
{
  system(("ls --file-type " + path + " | grep / > /tmp/dirs.tmp 2> /dev/null").c_str());
  std::ifstream ifs;
  ifs.open("/tmp/dirs.tmp");
  std::vector<std::string> dirVec;
  std::string line;

  while (std::getline(ifs, line))
  {
    if(line != "")
    {
      line = path + line; // add folder name + '/'
      dirVec.push_back(line);
    }
  }
  ifs.close();
  return dirVec;
}

std::vector<std::string> listFilesInDirectory(const std::string path) // return a list of path with no '/' at the end
{
  system(("ls --file-type " + path + " | grep -v / > /tmp/files.tmp 2> /dev/null").c_str());
  std::ifstream ifs;
  ifs.open("/tmp/files.tmp");
  std::vector<std::string> dirVec;
  std::string line;

  while (std::getline(ifs, line))
  {
    if(line != "")
    {
      line = path + line; // add file name
      dirVec.push_back(line);
    }
  }
  ifs.close();
  return dirVec;
}

std::vector<std::string> fileToStringVector(std::string path)
{
  std::vector<std::string> toBeReturned;
  std::string line;

  std::ifstream ifs;
  ifs.open(path);
  while (std::getline(ifs, line))
  {
    if(line != "")
    {
      toBeReturned.push_back(line);
    }
  }
  ifs.close();
  
  return toBeReturned;
}