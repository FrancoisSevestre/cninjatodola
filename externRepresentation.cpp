// std libraries
#include <string>
#include <vector>
//custom libraries
#include "ninjatodolaobject.hpp"
#include "ninjatodolalist.hpp"
#include "ninjatodolaobject.hpp"

//Theme variable
std::string indentationString("   ");

//colors
  //start
std::string hightlightGreen("\x1b[6;30;42m"), normal("\x1b[0m"), hightlightBlue("\x1b[0;30;44m"), hightlightBlack("\x1b[0;35;40m"), hightlightRed("\x1b[0;33;41m"), hightlightYellow("\x1b[6;34;43m");
std::string coloredRed("\033[91m"),coloredGreen("\033[92m"), coloredYellow("\033[93m"), coloredPurple("\033[94m"), coloredViolet("\033[95m"), coloredBlue("\033[96m"), coloredGrey("\033[97m"), coloredBlack("\033[98m");

  //end
std::string endHightlight("\x1b[0m");
std::string endColored("\033[00m");

//Theme function
std::string colorize(std::string start, std::string toBeColorized, std::string end)
{
  std::string toReturn;
  toReturn = start + toBeColorized + end;
  return toReturn;
}

std::string globalRepr(std::vector<NinjatodolaObject*> vecToBeReprensented)
{
  // initialize string that will be returned
  std::string globalRepresentation;

  //append the string for each element of the vector
     //for each element
  for (long unsigned int i(0); i<vecToBeReprensented.size(); i++)
    {
      int elementIndent = vecToBeReprensented[i]->getIndent();
      int elementPosition = vecToBeReprensented[i]->getPositionInMotherList();
      bool elementHighlight = vecToBeReprensented[i]->getHightlight(); // Not implemented yet
      std::string elementSelfRepr = vecToBeReprensented[i]->getSelfRepr();

     //for each type of object
      if (vecToBeReprensented[i]->getType() == "TaskList")
        {
          //TaskList representation
          std::string elementRepresentation(""); // reinit
          for (int i(0); i<elementIndent; i++) //Add indent
            {
              elementRepresentation += indentationString;
            }
          std::string stringPosition;
          stringPosition = std::to_string(elementPosition); // Convert position to string
          elementRepresentation += stringPosition; //add position
          elementRepresentation += "."; //add a separator
          std::string colorizedElementRepresentation;
            // if highlighted
          if (elementHighlight)
            {
          colorizedElementRepresentation = colorize(hightlightGreen, elementSelfRepr, endHightlight);
            }
            //else
          else
            {
              colorizedElementRepresentation = elementSelfRepr;
            }
          elementRepresentation += colorizedElementRepresentation; //add self representation
          elementRepresentation += "\n"; // finish line
          globalRepresentation += elementRepresentation;
        }
      
      else if (vecToBeReprensented[i]->getType() == "Command")
      {
          //Command representation
          std::string elementRepresentation(""); // reinit
          for (int i(0); i<elementIndent; i++) //Add indent
            {
              elementRepresentation += indentationString;
            }
          std::string stringPosition;
          stringPosition = std::to_string(elementPosition); // Convert position to string
          elementRepresentation += stringPosition; //add position
          elementRepresentation += "> "; //add a separator
          std::string colorizedElementRepresentation;
            // if highlighted
          if (elementHighlight)
            {
          colorizedElementRepresentation = colorize(hightlightBlue, elementSelfRepr, endHightlight);
            }
            //else
          else
            {
              colorizedElementRepresentation = colorize(coloredYellow, elementSelfRepr, endColored);
            }
          elementRepresentation += colorizedElementRepresentation; //add self representation
          elementRepresentation += "\n"; // finish line
          globalRepresentation += elementRepresentation;
      }
      
      else if (vecToBeReprensented[i]->getType() == "Application")
      {
          //Command representation
          std::string elementRepresentation(""); // reinit
          for (int i(0); i<elementIndent; i++) //Add indent
            {
              elementRepresentation += indentationString;
            }
          std::string stringPosition;
          stringPosition = std::to_string(elementPosition); // Convert position to string
          elementRepresentation += stringPosition; //add position
          elementRepresentation += "."; //add a separator
          std::string colorizedElementRepresentation;
            // if highlighted
          if (elementHighlight)
            {
          colorizedElementRepresentation = colorize(hightlightBlue, elementSelfRepr, endHightlight);
            }
            //else
          else
            {
              colorizedElementRepresentation = colorize(coloredBlue, elementSelfRepr, endColored);
            }
          elementRepresentation += colorizedElementRepresentation; //add self representation
          elementRepresentation += "\n"; // finish line
          globalRepresentation += elementRepresentation;
      }
      // Insert new ObjectTypes HERE!
    }

  //return the string
  return globalRepresentation;
}
