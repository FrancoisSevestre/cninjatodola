#include "variousfunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

std::string singleCharacterInput()
{
  system("read -N 1 -t 30 variable  && echo $variable > /tmp/userChoice");
  std::ifstream tmpfile;
  std::string userChoice;
  tmpfile.open("/tmp/userChoice", std::ios::in);
  userChoice = tmpfile.get();
  return userChoice;

}
