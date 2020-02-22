// Standard libraries
#include <iostream>
#include <stdlib.h>

// Custom libraries
#include "ninjatodolaobject.h"
#include "ninjatodolalist.h"
#include "tasklist.h"
#include "externRepresentation.h"

using namespace std;

void mainListRepresentation(NinjatodolaObject *mainList)
{
  system("clear");
  vector<NinjatodolaObject*> vec;
  vec = mainList->repr(vec);
  string finalRepr;
  finalRepr = globalRepr(vec);
  cout << finalRepr << endl;
}

int NinjaTODOla()
{
  //manage save

  // Init
  TaskList mainList;
  mainList.setMotherList(&mainList);
  mainList.setSelfRepr("Liste principale");
  mainList.setPositionInMotherList(0);
  mainList.setIndent(0);

  NinjatodolaObject *currentObject(0);
  currentObject = &mainList;

//  NinjatodolaObject *objectCache(0);
  bool quitNinajtodola(false); // End the program if true

  // Main loop
  while (!quitNinajtodola)
    {
      // Display mainList
      currentObject->setHightlight(true);
      mainListRepresentation(&mainList);
      cout << "Que faire?" << endl;

      // Display menu

      // Ask user for action
      string userChoice;
      getline(cin, userChoice);

      // Main menu
      if(userChoice == "q")
        {
          quitNinajtodola = true;
        }

      else if(userChoice=="k") // delete the task
        {
          // Make sure not to kill the mainList
          if(&currentObject->getMotherList() != currentObject)
            {
              // change the current object to its motherLIst and kill it
              int positionOfCurrentObject(currentObject->getPositionInMotherList());
              currentObject = &currentObject->getMotherList();
              currentObject->kill(positionOfCurrentObject);
            }

        }

      else
        {
          // Object menu
          NinjatodolaObject* actionReturn;
          actionReturn = currentObject->action(userChoice);

          // Analyse choice
          currentObject = actionReturn;
        }

      // update
      mainList.update();
    }

  return 0;
}
