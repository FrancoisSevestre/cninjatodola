#include "ninjatodolaobject.h"
// Constructors
NinjatodolaObject::NinjatodolaObject(): attrSelfRepr("NinjaTODOla"), attrMotherList(this), attrPositionInMotherList(1), attrIndent(0), attrHightlight(false)
{}

NinjatodolaObject::NinjatodolaObject(std::string SelfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): attrSelfRepr(SelfRepr), attrMotherList(motherList), attrPositionInMotherList(positionInMotherList), attrIndent(Indent), attrHightlight(false)
{}

NinjatodolaObject::~NinjatodolaObject()
{}

// Accessers

//Get
std::string NinjatodolaObject::getSelfRepr() const
{
  return attrSelfRepr;
}

NinjatodolaObject& NinjatodolaObject::getMotherList() const
{
  return *attrMotherList;
}

int NinjatodolaObject::getPositionInMotherList() const
{
  return attrPositionInMotherList;
}

int NinjatodolaObject::getIndent() const
{
  return attrIndent;
}

bool NinjatodolaObject::getHightlight() const
{
  return attrHightlight;
}

//Set
void NinjatodolaObject::setSelfRepr(std::string const newSelfRepr)
{
  attrSelfRepr = newSelfRepr;
}

void NinjatodolaObject::setMotherList(NinjatodolaObject *newMotherList)
{
  attrMotherList = newMotherList;
}

void NinjatodolaObject::setPositionInMotherList(const int newPosition)
{
  attrPositionInMotherList = newPosition;
}

void NinjatodolaObject::setIndent(const int newIndent)
{
  attrIndent = newIndent;
}

void NinjatodolaObject::setHightlight(const bool newHightlight)
{
  attrHightlight = newHightlight;
}

// Methodes

//Representation
void NinjatodolaObject::switchHightlight()
{
  if (attrHightlight == false)
    {
      attrHightlight = true;
    }
  else
    {
      attrHightlight = false;
    }
}
