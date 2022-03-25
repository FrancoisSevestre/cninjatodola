#include <iostream>
#include "ninjatodolaobject.hpp"
#include "tasklist.hpp"
#include "externRepresentation.hpp"
#include "test_zone.hpp"
#include "NinjaTODOla.hpp"

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
