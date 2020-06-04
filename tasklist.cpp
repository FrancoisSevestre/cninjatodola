#include "tasklist.h"
// std libraries
#include <string>
#include <vector>
#include <stdlib.h>


// Constructors: Sub-optimal
TaskList::TaskList(): NinjatodolaList()
{
  setType("TaskList"); // Needs to be rectified
  setMessage("\nMenu d'objet:\n- Ajouter une tâche (+)\n- Supprimer une tâche (-)\n- Placer une tâche (/)\n- Ajouter un objet spécial ($)\n- Développer/Réduire (!)\n- Couper (X)\n- Coller (V)\n- Renommer la liste (r)");
}

TaskList::TaskList(std::string selfRepr, NinjatodolaObject *motherList, int positionInMotherList, int Indent): NinjatodolaList(selfRepr, motherList, positionInMotherList, Indent)
{
  setType("TaskList"); // Needs to be rectified
  setMessage("\nMenu d'objet:\n- Ajouter une tâche (+)\n- Supprimer une tâche (-)\n- Placer une tâche (/)\n- Ajouter un objet spécial ($)\n- Développer/Réduire (!)\n- Couper (X)\n- Coller (V)\n- Menu module (m)\n- Renommer la liste (r)\n- Executer une app de la liste (e)\n- Supprimer la liste (k)");
}
TaskList::~TaskList()
{
  // add destruction of the content
  for(int i(0); i<getListSize() - 1; i++)
    {
      delContent(i);
    }
}


//Object actions
NinjatodolaObject* TaskList::action(std::string action)
{
  NinjatodolaObject* toBeReturned(this); // the object return itself or another object
  if(action=="+") // Add a new sublist at the end of the list
    {
      // info: std::cout << "l'utilisateur souhaite ajouter un objet" << std::endl;
      addSubList(false);
    }

  else if(action=="/") // Add a new sublist at a specified position
    {
      //info: std::cout << "l'utilisateur souhaite ajouter un objet placé" << std::endl;
      addSubList(true);
    }

  else if(action=="-") // Del a sublist at a specified position
    {
      // info: std::cout << "l'utilisateur souhaite supprimer un objet" << std::endl;
      delSublist();
    }

  else if(action == "6") // Move right
    {
      // Verify that the object is not empty
      if(getListSize() > 0)
        {
          // Make the first item of the list the current object
          toBeReturned = attrContent[0];
        }
    }

  else if(action == "4") // Move left:
    {
      // Make the motherList the current object
      toBeReturned = &getMotherList();
    }

  else if(action == "8") // Mouve up
    {
      // Verify that the object is not the first of the list
      if(getPositionInMotherList() != 0)
        {
          // Make the previous object in the list the current object
          toBeReturned = getMotherList().getContent()[getPositionInMotherList() - 1];
        }
    }

  else if(action == "2") // Move down
    {
      // Verify that the object is not the last of the list
      int PositionInMotherListMax(getMotherList().getContent().size() - 1);
      if(getPositionInMotherList() != PositionInMotherListMax)
        {
          // Make the next object in the list the current object
          toBeReturned = getMotherList().getContent()[getPositionInMotherList() + 1];
        }
    }

  else if(action=="!") // Show/hide sublists  virtual NinjatodolaObject& getMotherList() const =0;
    {
      switchShow();
    }

  else if(action=="r") // rename the task
    {
      changeListName();
    }

  else if(action=="$") // add special objects in the list
    {
      //not implemented yet!
      std::cout << "\nPas encore implémenté" << std::endl;
      system("sleep 1");
    }

  else if(action=="X") // Copy the object and store it in chache
    {
      //not implemented yet!
      std::cout << "\nPas encore implémenté" << std::endl;
      system("sleep 1");
    }
  else if(action=="V") // paste the object from cache and add it into list
    {
      //not implemented yet!
      std::cout << "\nPas encore implémenté" << std::endl;
      system("sleep 1");
    }

  // return the next current object
  return toBeReturned;
}

void TaskList::addSubList(bool placed) // BUGGED! :after a placed, the taskname is empty
{
  // Ask the name of the sublist
  std::string taskName(""); // Non-void
  std::cout << "\nEnter a name: ";
  std::getline(std::cin, taskName); // User input

  //test
  if (taskName == "")
    {
      taskName = "Vide";
    }

  if(placed)
    {
      //Ask for position
      long unsigned int taskPosition;
      // Verify that user entered a proper int:
      bool isOK(false);
      while(!isOK)
        {
        std::cout << "Entrer une position: ";
        std::cin >> taskPosition;
        std::cin.ignore(); // debug

        if(std::cin.fail() || (taskPosition > attrContent.size())) // if user didn't enter proper position
          {
            // user didn't input a number
            std::cin.clear(); // reset failbit
            std::cout << "Ce n'est pas une position valide!" << std::endl;
            std::cin.ignore(256, '\n'); // discard characters
          }

        else
          {
            isOK = true;
          }
        }

      addContent(new TaskList(taskName, this, taskPosition, getIndent() + 1), taskPosition); // create a new TaskList and add the pointer to the list

    }
  else
    {
      int futurPosition; // The futur position of the freshly created object
      if (getListSize()<1) // if the list is empty
        {
          futurPosition = 0;
        }
      else // if the liste is not empty
        {
          futurPosition = getListSize() + 1;
        }
      addContent(new TaskList(taskName, this, futurPosition, getIndent() + 1)); // create a new TaskList and add the pointer to the list
    }
}

void TaskList::delSublist()
{
  //Check if list is not empty
  if (getListSize()<1)
    {
      std::cout << "\nLa liste est vide! " << std::endl;
      system("sleep 1"); //Sleep for 1 sec (UNIX only)
    }
  else
    {
      //Ask for position
      long unsigned int taskPosition;
      // Verify that user entered a proper int:
      std::cout << "\nEntrer une position: ";
      std::cin >> taskPosition;
      std::cin.ignore(); // debug

      if(std::cin.fail() || (taskPosition > attrContent.size() - 1)) // if user didn't enter proper position
        {
          // user didn't input a number
          std::cin.clear(); // reset failbit
          std::cout << "Ce n'est pas une position valide!" << std::endl;
          std::cin.ignore(256, '\n'); // discard characters
        }
      else
        {
          delContent(taskPosition);
        }
    }
}

void TaskList::changeListName()
{
  std::string newListName;
  std::cout << "\nEntrer le nouveau nom de la liste: " << std::endl;
  std::getline(std::cin, newListName); // Ask user for new list name
  setSelfRepr(newListName);
}

//Representation
std::vector<NinjatodolaObject*> TaskList::repr(std::vector<NinjatodolaObject*> vec)
{
  // create a vector of ninjatodolaobjects
  std::vector<NinjatodolaObject*> reprVector(vec);

  // add self to vector
  reprVector.push_back(this);

  // pass to content
  for(long unsigned int i(0); i<attrContent.size(); i++) // for each contend object
    {
      reprVector = attrContent[i]->repr(reprVector);
    }
  //return vector
  return reprVector;
}

//Special
void TaskList::update() //reorder and unhighlight things
{
  setHightlight(false);
  for(unsigned long int i(0); i<attrContent.size(); i++)
    {
      attrContent[i]->setIndent(getIndent() + 1);
      attrContent[i]->setMotherList(this);
      attrContent[i]->setHightlight(false);
      attrContent[i]->setPositionInMotherList(i);
      attrContent[i]->update();

    }
}

void TaskList::kill(int position)
{
  delContent(position);
}
