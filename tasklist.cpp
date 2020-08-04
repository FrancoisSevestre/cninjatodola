#include "tasklist.hpp"
#include "variousfunctions.hpp"
#include "command.hpp"

// std libraries
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>


// Constructors: Sub-optimal
TaskList::TaskList(): NinjatodolaList()
{
  setType("TaskList"); // Needs to be rectified
  setMessage("\nMenu d'objet:\n- Ajouter une tâche (+)\n- Supprimer une tâche (-)\n- Placer une tâche (/)\n- Ajouter un objet spécial ($)\n- Développer/Réduire (!)\n- Couper (X)\n- Coller (V)\n- Renommer la liste (r)");
}
TaskList::TaskList(TaskList *ListeToCopy)
{
  setType("TaskList"); // Needs to be rectified
  setMessage("\nMenu d'objet:\n- Ajouter une tâche (+)\n- Supprimer une tâche (-)\n- Placer une tâche (/)\n- Ajouter un objet spécial ($)\n- Développer/Réduire (!)\n- Couper (X)\n- Coller (V)\n- Menu module (m)\n- Renommer la liste (r)\n- Executer une app de la liste (e)\n- Supprimer la liste (k)");
  setSelfRepr(ListeToCopy->getSelfRepr());
  setMotherList(&ListeToCopy->getMotherList());
  setPositionInMotherList(ListeToCopy->getPositionInMotherList());
  setIndent(ListeToCopy->getIndent());
  for(int i(0); i<attrContent.size() -1; i++)
  {
    ListeToCopy->addContent(attrContent[i]);
  }
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
      std::cout << "Quel type d'objet ajouter?\n1-Application\n2-Commande\n3-Lien vers une liste\n4-Dossier\n5-Fichier\n>";
      long unsigned int typeChoice;
      std::cin >> typeChoice;
      std::cin.ignore();
      if(!std::cin.fail()) //To verify
      {
          if(typeChoice == 1)
          {
              addApplication();
          }
          else if (typeChoice == 2)
          {
              addCommand();
          }
          else if (typeChoice == 3)
          {
              addLink();
          }
          else if (typeChoice == 4)
          {
              addDirectory();
          }
          else if (typeChoice == 5)
          {
              addFile();
          }
          else
          {
              std::cout << "Erreur: Le choix n'est pas dans la liste." << std::endl;
          }
      }
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

void TaskList::addApplication()
{

}

void TaskList::addCommand()
{
  //Ask for position
  long unsigned int commandPosition;
  // Verify that user entered a proper int:
  bool isOK(false);
  while(!isOK)
  {
    std::cout << "Entrer une position: ";
    std::cin >> commandPosition;
    std::cin.ignore(); // debug

    if(std::cin.fail() || (commandPosition > attrContent.size())) // if user didn't enter proper position
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

  addContent(new Command(true), commandPosition); // create a new Command and add the pointer to the list

}

void TaskList::addLink()
{

}

void TaskList::addDirectory()
{

}

void TaskList::addFile()
{
  
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

std::string TaskList::saveAsString()
{
  //save list string
  std::string saveString;
  saveString += std::to_string(attrIndent) + ";";
  saveString += attrType + ";";
  saveString += attrSelfRepr + ";";
  saveString += std::to_string(attrShow) + ";";
  saveString += "\n";

  //add liste content
  for(unsigned long int i(0); i<attrContent.size(); i++)
  {
    saveString += attrContent[i]->saveAsString();
  }
  return saveString;
}

void TaskList::loadFromString(std::vector<std::string> saveString)
{
  // load self from the first line
    //get attr
  int indent = stoi(cutString(saveString[0], ";")[0]);
  std::string type = cutString(saveString[0], ";")[1];
  std::string selfRepr = cutString(saveString[0], ";")[2];
  bool show = stoi(cutString(saveString[0], ";")[3]);
    //change attr of self
  setIndent(indent);
  setType(type); //useless
  setSelfRepr(selfRepr);
  setShow(show);

  saveString.erase(saveString.begin()); // erase first line
  bool finished(false);
  while(!finished)
  {
    if (saveString.size() > 1) //if there is several objects on the list
    {
      bool found(false);
      //the first line as ident +1
      for(int i(1); i<saveString.size(); i++) //find the next ident +1 position
      {
        if (found)
        {
          break; // if already found, no more search
        }

        if(stoi(cutString(saveString[i], ";")[0]) == getIndent()+1) // if found
        {
          //position is i
          found = true;
          std::vector<std::string> subSaveString; //create sub-vector

          for(int z(0); z != i; z++)// fill the sub-vector (i+1)
          {
            subSaveString.push_back(saveString[z]);
          }
          //erase from vector
          saveString.erase(saveString.begin(), saveString.begin() + i);

          // Create object
          if(cutString(subSaveString[0], ";")[1] == "TaskList") // Find what kind of object to create
          {
            TaskList *newList;
            newList = new TaskList();
            newList->loadFromString(subSaveString);
            addContent(newList);
          }
          else if(cutString(subSaveString[0], ";")[1] == "Command") // Find what kind of object to create
          {
            Command *newCommand;
            newCommand = new Command();
            newCommand->loadFromString(subSaveString);
            addContent(newCommand);
          }

        }
      }
      if(!found) //not found
      {
        //not found at all => the rest of the liste belongs to first line
        std::vector<std::string> subSaveString; //create sub-vector
        for(int z(0); z<saveString.size(); z++)// fill the sub-vector
        {
        subSaveString.push_back(saveString[z]);
        }
        //erase from vector
        saveString.erase(saveString.begin(), saveString.end());

        // Create object
        if(cutString(subSaveString[0], ";")[1] == "TaskList") // Find what kind of object to create
        {
          TaskList *newList;
          newList = new TaskList();
          newList->loadFromString(subSaveString);
          addContent(newList);
        }
        else if(cutString(subSaveString[0], ";")[1] == "Command") // Find what kind of object to create
          {
            Command *newCommand;
            newCommand = new Command();
            newCommand->loadFromString(subSaveString);
            addContent(newCommand);
          }
      }
    }

    if(saveString.size() == 1) // if there is only on objects in the list
    {
        if(cutString(saveString[0], ";")[1] == "TaskList") // Find what kind of object to create
          {
            TaskList *newList;
            newList = new TaskList();
            newList->loadFromString(saveString);
            addContent(newList);
          }
          else if(cutString(saveString[0], ";")[1] == "Command") // Find what kind of object to create
          {
            Command *newCommand;
            newCommand = new Command();
            newCommand->loadFromString(saveString);
            addContent(newCommand);
          }
    finished = true;
    }

    if(saveString.size() < 1) // if the list is empty
    {
      finished = true;
    }
  }
}

void TaskList::kill(int position)
{
  delContent(position);
}
