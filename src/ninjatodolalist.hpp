#ifndef NINJATODOLALIST_H
#define NINJATODOLALIST_H

// standard library
#include "ninjatodolaobject.hpp"
#include <vector>


/**
 * Base class of the ninjatodola lists.
 *
 * Can return a list of pointeur that it contains using listRepr().
 * Content can be shown of not.
 *
 */
class NinjatodolaList : public NinjatodolaObject
{
protected:
  std::vector<NinjatodolaObject*> attrContent; //vector containing ninjatodolaobjects
  bool attrShow; // if false, content should be hided

public:
  // Constructors
  NinjatodolaList();
  NinjatodolaList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent);

  // Accessers

  //Get
  std::vector<NinjatodolaObject*> getContent() const;
  bool getShow() const;
  int getListSize() const;

  //Set
  void setShow(bool const newShow);
  void switchShow();
  /**
   * Add the object at the end of the content list.
   * @param *Object is a pointer of a NinjatodolaObject.
   */
  void addContent(NinjatodolaObject *Object);
  /**
   * Add the object at the given position in the content list.
   * @param *Object is a pointer of a NinjatodolaObject.
   * @param position is comprised between 0 and the liste length -1.
   */
  void addContent(NinjatodolaObject *Object, int position);
  /**
   * Delete the object at the given position in the content list.
   * @param *Object is a pointer of a NinjatodolaObject.
   */
  void delContent(int position);

  // Methodes

  //Representation
};

#endif // NINJATODOLALIST_H
