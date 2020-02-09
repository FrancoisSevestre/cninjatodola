#include "ninjatodolalist.h"

// Constructors
NinjatodolaList::NinjatodolaList() : NinjatodolaObject(), attrShow(true)
{
  setType("NinjatodolaList");
}

NinjatodolaList::NinjatodolaList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): NinjatodolaObject(selfRepr, motherList, positionInMotherList, Indent), attrShow(true)
{
  setType("NinjatodolaList");
}

// Accessers

//Get
std::vector<NinjatodolaObject*> NinjatodolaList::getContent() const
{
  return attrContent;
}
bool NinjatodolaList::getShow() const
{
  return attrShow;
}

//Set
void NinjatodolaList::setShow(const bool newShow)
{
  attrShow = newShow;
}

void NinjatodolaList::addContent(NinjatodolaObject *Object)
{
  attrContent.push_back(Object);
}

void NinjatodolaList::addContent(NinjatodolaObject *Object, int position)
{
  attrContent.insert(attrContent.begin()+position, Object);
}

void NinjatodolaList::delContent(int position)
{
  attrContent.erase(attrContent.begin()+position);
}
