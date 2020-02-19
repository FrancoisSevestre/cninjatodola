#include <iostream>
#include "ninjatodolaobject.h"
#include "tasklist.h"
#include "externRepresentation.h"
#include <stdlib.h>

using namespace std;

void mainListRepresentation(TaskList *mainList)
{
  system("clear");
  vector<NinjatodolaObject*> vec;
  vec = mainList->repr(vec);
  string finalRepr;
  finalRepr = globalRepr(vec);
  cout << finalRepr << endl;
}

int Test()
{
  // Test the repr function
    TaskList liste1;
    liste1.setMotherList(&liste1);
    liste1.setSelfRepr("Liste principale");
    liste1.setPositionInMotherList(0);

    TaskList liste2("Liste secondaire", &liste1, 0, 1);
    TaskList liste3("Liste secondaire2", &liste1, 1, 1);
    TaskList liste4("Liste tertiaire", &liste2, 0, 2);
    TaskList liste5("Liste secondaire3", &liste1, 3, 1);

    liste1.addContent(&liste2);
    liste1.addContent(&liste3);
    liste2.addContent(&liste4);
    liste1.addContent(&liste5);


    TaskList *currentObject(&liste1);
    while(true)
      {
        currentObject->setHightlight(true);
        mainListRepresentation(currentObject);
        cout << "Que faire?" << endl;
        string userChoice;
        getline(cin, userChoice);
        currentObject->action(userChoice);
      }


    // end test
  return 0;
}
