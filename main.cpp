#include <iostream>
#include "ninjatodolaobject.h"
#include "tasklist.h"
#include "externRepresentation.h"
#include "test_zone.h"
#include "NinjaTODOla.h"

using namespace std;

int main()
{
  cout << "Welcome to NinjaTODOla in C++" << endl<< endl; // Welcome message
  bool testing(false); // Choose if you want to launch the test zone
  if(testing)
    {
      return Test();
    }
  else
    {
      return NinjaTODOla();
    }
}
