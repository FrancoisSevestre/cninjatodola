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
