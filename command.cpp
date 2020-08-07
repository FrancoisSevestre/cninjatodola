#include "command.hpp"
#include <string>
#include <vector>
#include <iostream>

#include "variousfunctions.hpp"

Command::Command() :NinjatodolaObject()
{
    setType("Command");
    setMessage("\nMenu d'objet:\n- Exécuter (e)\n- Couper (X)\n- Réécrire la commande (r)\n- Supprimer la liste (k)");
    setSelfRepr("pas de commande entrée");
    setLanguage("bash");
}

Command::Command(bool commandToBeSet)
{
    setType("Command");
    setMessage("\nMenu d'objet:\n- Exécuter (e)\n- Couper (X)\n- Réécrire la commande (r)\n-Changer de language (l)\n- Supprimer la liste (k)");
    setLanguage("bash");
    if(commandToBeSet)
    {
        setCommand();
    }
}
// Command::Command(Command *toCopy)
// {}

Command::~Command()
{}

//Sets
void Command::setCommand()
{
    std::string newCommand;
    std::cout << "\nEntrer la commande: " << std::endl;
    std::getline(std::cin, newCommand); // Ask user for new command
    setSelfRepr(newCommand);
}

void Command::setLanguage()
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

void Command::setLanguage(std::string language)
{
    attrLanguage = language;
}

//Gets
std::string Command::getLanguage()
{
    return attrLanguage;
}

void Command::executeSelf()
{
    if(attrLanguage == "bash")
    {
        std::string commandToBeExecuted("echo \"\n==========\n\" && " + attrSelfRepr + ";sleep 2");
        system(commandToBeExecuted.c_str());       
    }
    else if (attrLanguage == "python")
    {
        std::cout << "Pas encore implémenté" << std::endl;
    }
}

//Object actions
NinjatodolaObject* Command::action(std::string action)
{
    NinjatodolaObject* toBeReturned(this); // the object return itself or another object
    if(action=="e")
    {
        executeSelf();
    }

    else if(action=="r")
    {
        setCommand();
    }

    else if(action=="l")
    {
        setLanguage();
    }

    else if(action=="X")
    {
        //not implemented yet!
    }

    else if(action=="4")
    {
        toBeReturned = &getMotherList(); // Make the motherList the current object
    }

    else if(action=="8")
    {
        // Verify that the object is not the first of the list
        if(getPositionInMotherList() != 0)
            {
            // Make the previous object in the list the current object
            toBeReturned = getMotherList().getContent()[getPositionInMotherList() - 1];
            }
    }

    else if(action=="2")
    {
        // Verify that the object is not the last of the list
        int PositionInMotherListMax(getMotherList().getContent().size() - 1);
        if(getPositionInMotherList() != PositionInMotherListMax)
        {
            // Make the next object in the list the current object
            toBeReturned = getMotherList().getContent()[getPositionInMotherList() + 1];
        }
    }
    
    return toBeReturned;
}

std::vector<NinjatodolaObject*> Command::getContent() const
{
    std::vector<NinjatodolaObject*> nullV;
    return nullV;
}

std::vector<NinjatodolaObject*> Command::repr(std::vector<NinjatodolaObject*> vec)
{
    vec.push_back(this);
    return vec;
}

void Command::update()
{
    setHightlight(false);
}

std::string Command::saveAsString()
{
    std::string saveString;
    saveString += std::to_string(attrIndent) + ";";
    saveString += attrType + ";";
    saveString += attrSelfRepr + ";";
    saveString += attrLanguage + ";";
    saveString += "\n";
    return saveString;
}

void Command::loadFromString(std::vector<std::string> saveString)
{
    // saved string : indent;type;selfRepr;language
    //get attr
    int indent = stoi(cutString(saveString[0], ";")[0]);
    std::string type = cutString(saveString[0], ";")[1];
    std::string selfRepr = cutString(saveString[0], ";")[2];
    std::string language = cutString(saveString[0], ";")[3];
    //change attr of self
    setIndent(indent);
    setType(type); //useless
    setSelfRepr(selfRepr);
    setLanguage(language);
}

void Command::kill(int position)
{
    position = position; //useless
}