#include "Application.hpp"

//custom libraries
#include "variousfunctions.hpp"
#include "command.hpp"

// std libraries
#include <string>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <fstream>

//Constructors
Application::Application(bool ApptoBeSet) :NinjatodolaList()
{
    setType("Application");
    setMessage("\nMenu d'objet:\n- Ajouter une commande (+)\n- Supprimer une commande (-)\n- Placer une commande (/)\n- Executer (e)\n- Changer le language (l)\n- Développer/Réduire (!)\n- Afficher le résultat de l'execution (:)\n- Couper (X)\n- Coller (V)\n- Renommer la liste (r)");
    setInterpret(false);
    setShow(true);
    setLanguage("bash");
    if(ApptoBeSet)
    {
        changeAppName();
    }
}

Application::Application(Application *listeToCopy) :NinjatodolaList()
{
    setName(listeToCopy->getSelfRepr());
    setShow(listeToCopy->getShow());
    setMessage(listeToCopy->getMessage());
    setHightlight(listeToCopy->getHightlight());
    setIndent(listeToCopy->getIndent());
    setInterpret(listeToCopy->getInterpret());
    setLanguage(listeToCopy->getLanguage());
    setMotherList(&listeToCopy->getMotherList());
    setPositionInMotherList(listeToCopy->getPositionInMotherList());
    setType(listeToCopy->getType());
    //copy content
}

Application::~Application()
{
    // add destruction of the content
    for(int i(0); i<getListSize() - 1; i++)
        {
        delContent(i);
        }
}

//methodes
NinjatodolaObject* Application::action(std::string action)
{
  NinjatodolaObject* toBeReturned(this); // the object return itself or another object
  if(action=="+") // Add a new command at the end of the list
    {
      addCommand(false);
    }

  else if(action=="/") // Add a new command at a specified position
    {
      addCommand(true);
    }

  else if(action=="-") // Del a command at a specified position
    {
      // info: std::cout << "l'utilisateur souhaite supprimer un objet" << std::endl;
      delCommand();
    }

  else  if(action=="e")
    {
        executeSelf(false);
    }

  else if(action == "6") // Move right
    {
      setShow(true);
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

  else if(action=="!") // Show/hide commands  virtual NinjatodolaObject& getMotherList() const =0;
    {
      switchShow();
    }

  else if(action==":") // Add a new command at a specified position
    {
      switchInterpret();
      update();
    }

  else if(action=="r") // rename the task
    {
      changeAppName();
    }

  else if(action=="l") // Add a new command at a specified position
    {
      setLanguage();
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

void Application::changeAppName()
{
    std::string newName;
    std::cout << "\nEntrer le nouveau nom: " << std::endl;
    std::getline(std::cin, newName); // Ask user for new Name
    setName(newName);
    
}

void Application::addCommand(bool placed)
{
  //test
  if(placed)
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

      addContent(new Command(true), commandPosition); // create a new App and add the pointer to the list

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
      addContent(new Command(true)); // create a new App and add the pointer to the list
    }
}
void Application::delCommand()
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
      long unsigned int appPosition;
      // Verify that user entered a proper int:
      std::cout << "\nEntrer une position: ";
      std::cin >> appPosition;
      std::cin.ignore(); // debug

      if(std::cin.fail() || (appPosition > attrContent.size() - 1)) // if user didn't enter proper position
        {
          // user didn't input a number
          std::cin.clear(); // reset failbit
          std::cout << "Ce n'est pas une position valide!" << std::endl;
          std::cin.ignore(256, '\n'); // discard characters
        }
      else
        {
          delContent(appPosition);
        }
    }
}

void Application::setLanguage()
{
    std::cout << "Quel language utiliser?\n1-Bash\n2-Python\n>";
    long unsigned int languageChoice;
    std::cin >> languageChoice;
    std::cin.ignore();
    if(!std::cin.fail()) //To verify
    {
        if(languageChoice == 1)
        {
            attrLanguage = "bash";
        }
        else if (languageChoice == 2)
        {
            attrLanguage = "python";
        }
        else
        {
            attrLanguage = "bash";
            std::cout << "Erreur: Le choix n'est pas dans la liste." << std::endl;
        }
    }
}

void Application::setLanguage(std::string language)
{
    attrLanguage = language;
}

void Application::setName(std::string name)
{
    attrName = name;
}
//Gets

std::string Application::getName()
{
    return attrName;
}
std::string Application::getLanguage()
{
    return attrLanguage;
}

void Application::switchInterpret()
{
    if(attrInterpret)
    {
      setInterpret(false);
    }
    else
    {
      setInterpret(true);
    }
}

void Application::setInterpret(bool interpret)
{
    attrInterpret = interpret;
}

bool Application::getInterpret()
{
    return attrInterpret;
}

void Application::executeSelf(bool exportOutput=false)
{
    if(attrLanguage == "bash")
    {
        if(!exportOutput)
        {
        std::string commandToBeExecuted;
        commandToBeExecuted += "echo \"\n==========\n\" && ";
        for(long unsigned int i(0); i<attrContent.size(); i++) // for each contend object
        {
        commandToBeExecuted += attrContent[i]->getSelfRepr();
        commandToBeExecuted += " && "; //separates each command
        }
        commandToBeExecuted += "sleep 2";
        system(commandToBeExecuted.c_str());
        }

        else
        {
            std::string commandToBeExecuted;
            for(long unsigned int i(0); i<attrContent.size(); i++) // for each contend object
            {
                commandToBeExecuted += attrContent[i]->getSelfRepr();
                commandToBeExecuted += " > /tmp/appOutput.tmp && "; //separates each command
            }
            commandToBeExecuted += "sleep 0";
            system(commandToBeExecuted.c_str()); 
            std::ifstream appOutput;
            appOutput.open("/tmp/appOutput.tmp");
            std::string stringOutput;
            getline(appOutput, stringOutput);
            appOutput.close();
            remove("/tmp/appOutput.tmp");
            setSelfRepr(stringOutput);

        }
    }
    else if (attrLanguage == "python")
    {
        std::cout << "Pas encore implémenté" << std::endl;
    }
}

std::vector<NinjatodolaObject*> Application::repr(std::vector<NinjatodolaObject*> vec)
{
  // create a vector of ninjatodolaobjects
  std::vector<NinjatodolaObject*> reprVector(vec);

  // add self to vector
    //update SelfRepr  
  reprVector.push_back(this); //sent it instead of this

    if(attrShow)
    {
    // pass to content
    for(long unsigned int i(0); i<attrContent.size(); i++) // for each contend object
      {
        reprVector = attrContent[i]->repr(reprVector);
      }
    }
  //return vector
  return reprVector;
}

void Application::update()
{
  setHightlight(false);
if(!attrInterpret)
{
    attrSelfRepr = attrName;
}
else
{
    executeSelf(true);
}

  for(unsigned long int i(0); i<attrContent.size(); i++)
    {
      attrContent[i]->setIndent(getIndent() + 1);
      attrContent[i]->setMotherList(this);
      attrContent[i]->setHightlight(false);
      attrContent[i]->setPositionInMotherList(i);
      attrContent[i]->update();

    }
}

std::string Application::saveAsString()
{
  // saved string : indent;type;selfRepr;language;interpret;show
  std::string saveString;
  saveString += std::to_string(attrIndent) + ";";
  saveString += attrType + ";";
  saveString += attrName + ";";
  saveString += attrLanguage + ";";
  saveString += std::to_string(attrInterpret) + ";";
  saveString += std::to_string(attrShow) + ";";
  saveString += "\n";

  //add liste content
  for(unsigned long int i(0); i<attrContent.size(); i++)
  {
    saveString += attrContent[i]->saveAsString();
  }
  return saveString;
}

void Application::loadFromString(std::vector<std::string> saveString)
{
    //get attr
    int indent = stoi(cutString(saveString[0], ";")[0]);
    std::string type = cutString(saveString[0], ";")[1];
    std::string name = cutString(saveString[0], ";")[2];
    std::string language = cutString(saveString[0], ";")[3];
    bool interpret = stoi(cutString(saveString[0], ";")[4]);
    bool show = stoi(cutString(saveString[0], ";")[5]);

    //change attr of self
    setIndent(indent);
    setType(type); //useless
    setName(name);
    setLanguage(language);
    setInterpret(interpret);
    setShow(show);

  saveString.erase(saveString.begin()); // erase first line

    for (int i(0); i<saveString.size(); i++) // ad command for each line
    {
        std::vector<std::string > subSaveString;
        subSaveString.push_back(saveString[i]);

        Command *newCommand;
        newCommand = new Command();
        newCommand->loadFromString(subSaveString);
        addContent(newCommand);
    }
}

void Application::kill(int position)
{
  delContent(position);
}