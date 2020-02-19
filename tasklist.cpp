#include "tasklist.h"
// std libraries
#include <string>
#include <vector>

// Constructors
TaskList::TaskList(): NinjatodolaList()
{
  setType("TaskList");
}

TaskList::TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): NinjatodolaList(selfRepr, motherList, positionInMotherList, Indent)
{
  setType("TaskList");
}
TaskList::~TaskList()
{

}

// Methodes

//Object actions
void TaskList::action(std::string action)
{
  if(action=="+")
    {
      std::cout << "l'utilisateur souhaite ajouter un objet" << std::endl;
      addSubList(false);
    }
  if(action=="/")
    {
      std::cout << "l'utilisateur souhaite ajouter un objet placé" << std::endl;
      addSubList(true);
    }
}

void TaskList::addSubList(bool placed)
{
  // Ask the name of the sublist
  std::string taskName;
  std::cout << "Enter a name: ";
  std::getline(std::cin, taskName);

  if(placed)
    {
      //Ask for position
      int taskposition;
      std::cout << "Enter a position: ";
      std::cin >> taskposition;
      addContent(new TaskList(taskName, this, taskposition, getIndent() + 1), taskposition); // create a new TaskList and add the pointer to the list

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
