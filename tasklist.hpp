#ifndef TASKLIST_H
#define TASKLIST_H

//custom libraries
#include "ninjatodolalist.hpp"

//standard libraries
#include <vector>
#include <string>



/**
 * Object that displays itself and its content in an ordonnated way.
 *
 */
class TaskList : public NinjatodolaList
{
protected:
  std::string attrMessage;
public:
  // Constructors
  TaskList();
  TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent);
  TaskList(TaskList *ListeToCopy);
  ~TaskList();

  // Methodes

  //Object actions: Return a vecotr of two NinjatodolaObjects (next current object
  // and an object to store in the cache).
  /**
    * Not filled yet!
    *
   */
  NinjatodolaObject* action(std::string action);

  /**
    * Not filled yet!
    *
   */
  void addSubList(bool placed);

  /**
    * Not filled yet!
    *
   */
  void delSublist();

  /**
    * Not filled yet!
    *
   */
  void changeListName();

  void addApplication();
  void addCommand();
  void addLink();
  void addDirectory();
  void addFile();
  //representation
  /**
   * Returns the ordonated representation
   * of the list and its content.
   * @param vec is a vector that will be append with pointers
   */
  std::vector<NinjatodolaObject*> repr(std::vector<NinjatodolaObject*> vec);

  //Special
  /**
   * Updates the content of the list (usefull in certain cases: e.g. folders).
   */
  void update();
  std::string saveAsString();
    /**
   * Changes the TaskList attr, adds its content and recursively order them to do the same thing.
   */
  void loadFromString(std::vector<std::string> saveString);
  void kill(int position);
};

#endif // TASKLIST_H
