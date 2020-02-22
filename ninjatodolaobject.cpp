#include "ninjatodolaobject.h"
// Constructors
NinjatodolaObject::NinjatodolaObject(): attrSelfRepr("NinjaTODOla"), attrMotherList(this), attrPositionInMotherList(1), attrIndent(0), attrHightlight(false), attrType("NinjatodolaObject")
{}

NinjatodolaObject::NinjatodolaObject(std::string SelfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): attrSelfRepr(SelfRepr), attrMotherList(motherList), attrPositionInMotherList(positionInMotherList), attrIndent(Indent), attrHightlight(false), attrType("NinjatodolaObject")
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

std::string NinjatodolaObject::getType()
{
  return attrType;
}

std::string NinjatodolaObject::getMessage()
{
  return attrMessage;
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

void NinjatodolaObject::setType(const std::string newType)
{
  attrType = newType;
}

void NinjatodolaObject::setMessage(const std::string newMessage)
{
  attrMessage = newMessage;
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
