// Standard libraries
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

// Custom libraries
#include "ninjatodolaobject.hpp"
#include "ninjatodolalist.hpp"
#include "tasklist.hpp"
#include "externRepresentation.hpp"
#include "variousfunctions.hpp"

using namespace std;

void mainListRepresentation(TaskList mainList)
{
  system("clear");
  vector<NinjatodolaObject*> vec;
  vec = mainList.repr(vec);
  string finalRepr;
  finalRepr = globalRepr(vec);
  cout << finalRepr << endl;
}

void saveList(NinjatodolaObject *list)
{
  vector<NinjatodolaObject*> vec;
  vec = list->repr(vec); // get every object ordered in a vector
  string saveFileName("Save.save"); //file name will depend on user's configuration later
  ofstream saveFile;//open a stream
  saveFile.open(saveFileName, ios::out);
  string saveString; //the string to be saved
  for(int i(0); i<vec.size(); i++)
  {
    string objectString; // line that will be saved for the object
    string indent;
    indent = to_string(vec[i]->getIndent());

    objectString += indent + ";";
    objectString += vec[i]->getType() + ";";
    objectString += vec[i]->getSelfRepr() + ";";
    string show;
    if (vec[i])
    {
      show = "1";
    }
    else
    {
      show = "0";
    }
    objectString += show + ";";
    saveString += objectString + "\n";
  }
  saveFile << saveString + "\n";
  saveFile.close();
}

vector<string> loadList()
{
  // open a stream
  string saveFileName("Save.save");
  ifstream saveFile;
  saveFile.open(saveFileName);
  // extract line by line
  vector<string> saveString;
  string line;
  while (getline(saveFile, line))
  {
    saveString.push_back(line);
  }
  saveFile.close();

  //erase empty last string
  saveString.erase(saveString.end());
  // return the mainList
  return saveString;
}

int NinjaTODOla()
{
  //manage save
    bool noSave;
    if(fileExists("Save.save"))
    {
      noSave = false;
    }
    else
    {
      noSave = true;
    }
    

  // Init:

  NinjatodolaObject *currentObject(0); //create a pointer to the current object
  TaskList mainList; // create mainlist object
  mainList.setMotherList(&mainList);
  mainList.setSelfRepr("Liste principale");
  mainList.setPositionInMotherList(0);
  mainList.setIndent(0);
  currentObject = &mainList;

  if (!noSave) // if there is a saveFile
    {
      mainList.loadFromString(loadList());
      mainList.update();
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
      // TaskList *mainListPtr(&mainList);//create a ptr to mainList
      mainListRepresentation(mainList) ; // represent the whole mainList

      // Display menu
      if(showMenu) // if menu is to be shown
        {
          cout << menuMessage << currentObject->getMessage() << endl; //menu Message+object Message
        }
      else // hide menu
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
      else if(userChoice=="m") //module menu: save and load lists in other lists
        {
          // not implemented yet!
          cout << "\nPas encore implémenté" << endl;
          system("sleep 1");
        }
      else if(userChoice=="L") // load or create a new mainlist
        {
          // not implemented yet
          cout << "\nPas encore implémenté" << endl;
          system("sleep 1");
        }

      else // if the action is object dependant
        {
          // Object menu : the object returns an other object or itself

          NinjatodolaObject* actionReturn;
          actionReturn = currentObject->action(userChoice);

          // Analyse choice
          currentObject = actionReturn; // the current object changes
          saveList(&mainList);
        }

      // update
      mainList.update();
      saveList(&mainList);
    }

  return 0;
}
