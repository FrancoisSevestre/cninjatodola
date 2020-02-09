#ifndef TASKLIST_H
#define TASKLIST_H
#include "ninjatodolalist.h"



/**
 * Object that displays itself and its content in an ordonnated way.
 *
 */
class TaskList : public NinjatodolaList
{
protected:
  std::string attrType;

public:
  // Constructors
  TaskList();
  TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent);
  ~TaskList();

  // Accessers

  //Get
  std::string getType();

  // Methodes

  //representation
  /**
   * Returns the ordonated representation
   * of the list and its content.
   */
  std::vector<NinjatodolaObject*> Repr();

  //Special
  void update();
};

#endif // TASKLIST_H
