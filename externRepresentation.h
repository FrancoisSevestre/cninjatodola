#ifndef EXTERNREPRESENTATION_H
#define EXTERNREPRESENTATION_H
// std libraries
#include <string>
#include <vector>
//custom libraries
#include "ninjatodolaobject.h"
#include "ninjatodolalist.h"
#include "ninjatodolaobject.h"

/**
 * Transform pointers list into a human readable list.\n
 * adds indent to show heritage.\n
 * adds position in motherlist.\n
 * adds highlight if needed.\n
 * hide list content if needed.\n
 * applies type specific theme.\n
 * @param vectToBeRepresented is a pointers list of NinjatodolaObjects.
 */
std::string globalRepr(std::vector<NinjatodolaObject*> vecToBeReprensented);



#endif // EXTERNREPRESENTATION_H
