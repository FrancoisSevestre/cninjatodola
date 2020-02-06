#ifndef NINJATODOLAOBJECT_H
#define NINJATODOLAOBJECT_H

// standard library
#include <iostream>
#include <string>


/**
 * Base class of every objects in ninjatodola.
 *
 * Can return a pointeur for representation using getSelf().
 * Should be contained in a mother list (except for the mainlist).
 * Can be:
 *
 */
class NinjatodolaObject
{
protected:
  std::string attrSelfRepr; // String representing the object (name, etc)
  NinjatodolaObject *attrMotherList; // List constaining the object
  int attrPositionInMotherList; // Position of the object in the list
  int attrIndent; // rank: motherlist rank + 1
  bool attrHightlight; // True if the object is selected


public:
  // Constructors
  NinjatodolaObject(); // Default constructor
  NinjatodolaObject(std::string SelfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent);
  virtual ~NinjatodolaObject(); // Destructor


  // Accessers

  //Get
  std::string getSelfRepr() const;
  NinjatodolaObject& getMotherList() const;
  int getPositionInMotherList() const;
  int getIndent() const;
  bool getHightlight() const;

  //Set
  void setSelfRepr(std::string const newSelfRepr);
  void setMotherList(NinjatodolaObject *newMotherList);
  void setPositionInMotherList(const int newPosition);
  void setIndent(const int newIndent);
  void setHightlight(const bool newHightlight);

  // Methodes

  //Representation
  /**
   * Change the hightlight status.
   */
  void switchHightlight();

  //Special
  /**
   * Update the object attributes.
   */
  virtual void update() = 0;


};

#endif // NINJATODOLAOBJECT_H
