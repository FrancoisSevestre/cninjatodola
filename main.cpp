#include <iostream>
#include "ninjatodolaobject.h"
#include "tasklist.h"
#include "externRepresentation.h"

using namespace std;

int main()
{
  cout << "Welcome to NinjaTODOla in C++" << endl<< endl;
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

  liste1.switchHightlight();

  vector<NinjatodolaObject*> vec;
  vec = liste1.repr(vec);
  string finalRepr;
  finalRepr = globalRepr(vec);
  cout << finalRepr << endl;



  // end test
  return 0;
}
