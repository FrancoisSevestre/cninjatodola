#include "tasklist.h"
// std libraries
#include <string>
#include <vector>
#include <stdlib.h>

// Constructors
TaskList::TaskList(): NinjatodolaList()
{
  setType("TaskList"); // Needs to be rectified
}

TaskList::TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): NinjatodolaList(selfRepr, motherList, positionInMotherList, Indent)
{
  setType("TaskList"); // Needs to be rectified
}
TaskList::~TaskList()
{
  // add destruction of the content
}

// Methodes

//Object actions
std::vector<NinjatodolaObject*> TaskList::action(std::string action)
{
  if(action=="+") // Add a new sublist at the end of the list
    {
      std::cout << "l'utilisateur souhaite ajouter un objet" << std::endl;
      addSubList(false);
    }

  if(action=="/") // Add a new sublist at a specified position
    {
      std::cout << "l'utilisateur souhaite ajouter un objet placé" << std::endl;
      addSubList(true);
    }

  update(); // update list content

  // Return of vector containing self only: next current object is self.
  std::vector<NinjatodolaObject*> toBeReturned(0);
  toBeReturned.push_back(this);
  return toBeReturned;
}

void TaskList::addSubList(bool placed)
{
  // Ask the name of the sublist
  std::string taskName(""); // Non-void
  std::cout << "Enter a name: ";
  std::getline(std::cin, taskName); // User input

  if(placed)
    {
      //Ask for position
      long unsigned int taskPosition;
      // Verify that user entered a proper int:
      bool isOK(false);
      while(!isOK)
        {
        std::cout << "Entrer une position: ";
        std::cin >> taskPosition;

        if(std::cin.fail() || (taskPosition > attrContent.size())) // if user didn't enter proper position
          {
            // user didn't input a number
            std::cin.clear(); // reset failbit
            std::cout << "Ce n'est pas une position valide!" << std::endl;
            std::cin.ignore(256, '\n'); // discard characters
          }

        else
          {
            isOK = true;
          }
        }

      addContent(new TaskList(taskName, this, taskPosition, getIndent() + 1), taskPosition); // create a new TaskList and add the pointer to the list

    }
  else
    {
      addContent(new TaskList(taskName, this, getListSize() + 1, getIndent() + 1)); // create a new TaskList and add the pointer to the list
    }
}


//representation
std::vector<NinjatodolaObject*> TaskList::repr(std::vector<NinjatodolaObject*> vec)
{
  // create a vector of ninjatodolaobjects
  std::vector<NinjatodolaObject*> reprVector(vec);

  // add self to vector
  reprVector.push_back(this);

  // pass to content
  for(long unsigned int i(0); i<attrContent.size(); i++) // for each contend object
    {
      reprVector = attrContent[i]->repr(reprVector);
    }
  //return vector
  return reprVector;
}

//Special
void TaskList::update()
{
  std::cout << "Update not implemented yet!" << std::endl;
}
