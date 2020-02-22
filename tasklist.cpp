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
NinjatodolaObject* TaskList::action(std::string action)
{
  NinjatodolaObject* toBeReturned(this);
  if(action=="+") // Add a new sublist at the end of the list
    {
      std::cout << "l'utilisateur souhaite ajouter un objet" << std::endl;
      addSubList(false);
    }

  else if(action=="/") // Add a new sublist at a specified position
    {
      std::cout << "l'utilisateur souhaite ajouter un objet placé" << std::endl;
      addSubList(true);
    }

  else if(action=="-") // Del a sublist at a specified position
    {
      std::cout << "l'utilisateur souhaite supprimer un objet" << std::endl;
      delSublist();
    }

  else if(action == "6") // Move right
    {
      // Verify that the object is not empty
      if(getListSize() > 0)
        {
          // Make the first item of the list the current object
          toBeReturned = attrContent[0];
        }
    }

  else if(action == "4") // Move left:
    {
      // Make the motherList the current object
      toBeReturned = &getMotherList();
    }

  else if(action == "8") // Mouve up
    {
      // Verify that the object is not the first of the list
      if(getPositionInMotherList() != 0)
        {
          // Make the previous object in the list the current object
          toBeReturned = getMotherList().getContent()[getPositionInMotherList() - 1];
        }
    }

  else if(action == "2") // Move down
    {
      // Verify that the object is not the last of the list
      int PositionInMotherListMax(getMotherList().getContent().size() - 1);
      if(getPositionInMotherList() != PositionInMotherListMax)
        {
          // Make the next object in the list the current object
          toBeReturned = getMotherList().getContent()[getPositionInMotherList() + 1];
        }
    }

  else if(action=="!") // Show/hide sublists  virtual NinjatodolaObject& getMotherList() const =0;
    {
      switchShow();
    }

  else if(action=="r") // rename the task
    {
      changeListName();
    }


  // return the next current object
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

void TaskList::delSublist()
{
  //Ask for position
  long unsigned int taskPosition;
  // Verify that user entered a proper int:
  std::cout << "Entrer une position: ";
  std::cin >> taskPosition;

  if(std::cin.fail() || (taskPosition > attrContent.size() - 1)) // if user didn't enter proper position
    {
      // user didn't input a number
      std::cin.clear(); // reset failbit
      std::cout << "Ce n'est pas une position valide!" << std::endl;
      std::cin.ignore(256, '\n'); // discard characters
    }
  else
    {
      delContent(taskPosition);
    }
}

void TaskList::changeListName()
{
  std::string newListName;
  std::cout << "Entrer le nouveau nom de la liste: " << std::endl;
  std::getline(std::cin, newListName); // Ask user for new list name
  setSelfRepr(newListName);
}

//Representation
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
  setHightlight(false);
  for(unsigned long int i(0); i<attrContent.size(); i++)
    {
      attrContent[i]->setIndent(getIndent() + 1);
      attrContent[i]->setMotherList(this);
      attrContent[i]->setHightlight(false);
      attrContent[i]->setPositionInMotherList(i);

    }
}

void TaskList::kill(int position)
{
  delContent(position);
}
