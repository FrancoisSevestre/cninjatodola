#ifndef TASKLIST_H
#define TASKLIST_H
#include "ninjatodolalist.h"



/**
 * Object that displays itself and its content in an ordonnated way.
 *
 */
class TaskList : public NinjatodolaList
{
public:
  // Constructors
  TaskList();
  TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent);
  ~TaskList();

  // Methodes

  //Object actions
  void action(std::string action);
  void addSubList(bool placed);

  //representation
  /**
   * Returns the ordonated representation
   * of the list and its content.
   * @param vec is a vector that will be append with pointers
   */
  std::vector<NinjatodolaObject*> repr(std::vector<NinjatodolaObject*> vec);

  //Special
  /**
   * To be implemented.
   * Updates the content of the list (usefull in certain cases: e.g. folders).
   */
  void update();
};

#endif // TASKLIST_H
