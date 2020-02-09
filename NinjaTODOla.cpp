// Standard libraries
#include <iostream>

// Custom libraries
#include "ninjatodolaobject.h"
#include "tasklist.h"
#include "externRepresentation.h"

using namespace std;

int NinjaTODOla()
{
  //manage save

  // Init
  TaskList mainList;
  mainList.setMotherList(&mainList);
  mainList.setSelfRepr("Liste principale");
  mainList.setPositionInMotherList(0);
  mainList.setIndent(0);

  TaskList *currentObject(0);
  currentObject = &mainList;

  // Main loop
  while (true)
    {
      // Clear screen
      //cout << "\n\n\n\n\n\n\n\n\n" << endl;
      // Update

      // Hightlight current object
      currentObject->switchHightlight();

      // Display mainList
      vector<NinjatodolaObject*> vec;
      vec = mainList.repr(vec);
      string mainListRepr;
      mainListRepr = globalRepr(vec);
      cout << mainListRepr << endl;

      // Display menu

      // Ask user for action

      // Analyse choice




    }
  return 0;
}
