#ifndef NINJATODOLA_H
#define NINJATODOLA_H

#include "ninjatodolaobject.h"
#include <string>
#include <vector>

/**
  * Generates the representation of the mainlist.
  * Uses the globalRepr function with the mainlist as argument.
  *
 */
void saveList(NinjatodolaObject *list);
std::vector<std::string> loadList();
void mainListRepresentation(NinjatodolaObject *mainList);
int NinjaTODOla();

#endif // NINJATODOLA_H
