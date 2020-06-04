// Standard libraries
#include <iostream>
#include <stdlib.h>

// Custom libraries
#include "ninjatodolaobject.h"
#include "ninjatodolalist.h"
#include "tasklist.h"
#include "externRepresentation.h"
#include "variousfunctions.h"

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
    //to be filled!
  bool noSave(true); //for now!

  // Init:

  NinjatodolaObject *currentObject(0); //create a pointer to the current object
  TaskList mainList; // create mainlist object

  if (noSave) // if no list is loaded
    {
      mainList.setMotherList(&mainList);
      mainList.setSelfRepr("Liste principale");
      mainList.setPositionInMotherList(0);
      mainList.setIndent(0);
      currentObject = &mainList;
    }
  else // if a list as been loaded
    {
      //then currentObject = this list
      // to be implemented!
    }

  string menuMessage("\nMenu Principal:\n- Monter dans l'arborescence (4)\n- Descendre dans l'arborescence (6)\n- Naviguer vers le bas (2)\n- Naviguer vers le haut (8)\n- Supprimer (k)\n- Choix liste principale (L)\n- Menu module (m)\n- Console (c)\n- Options (o)\n- Cacher l'aide (h)\n- Quitter (q)\n");
  bool showMenu(false);

//  NinjatodolaObject *objectCache(0); // if cache is implemented
  bool quitNinajtodola(false); // End the program if true

  // Main loop
  while (!quitNinajtodola)
    {
      // Display mainList
      currentObject->setHightlight(true); //hightlight the current object
      mainListRepresentation(&mainList); // represent the whole mainList

      // Display menu
      if(showMenu)
        {
          cout << menuMessage << currentObject->getMessage() << endl; //menu Message + object Message
        }
      else
        {
          cout << ("\n-Afficher l'aide (h)") << endl;
        }


      // Ask user for action
      string userChoice;
      userChoice = singleCharacterInput();

      // Main menu
        // if the action in not object dependant
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
      else if (userChoice=="c") // Use console
        {
          system("clear"); // clear screen
          system("cd ~ && $SHELL"); //lunch user's shell
        }
      else if (userChoice=="o") // goto options
        {
          //not implemented yet!
          cout << "\nPas encore implémenté" << endl;
          system("sleep 1");
        }
      else if(userChoice=="h") // Display help or not
        {
          if (showMenu)
            {
              showMenu = false;
            }
          else
            {
              showMenu = true;
            }
        }
      else // if the action is object dependant
        {
          // Object menu : the object returns an other object or itself

          NinjatodolaObject* actionReturn;
          actionReturn = currentObject->action(userChoice);

          // Analyse choice
          currentObject = actionReturn; // the current object changes
        }

      // update
      mainList.update();
    }

  return 0;
}
