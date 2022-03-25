#include "file.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "variousfunctions.hpp"

File::File() :NinjatodolaObject()
{
    setType("File");
    setMessage("\nMenu d'objet:\n- Exécuter (e)\n- Changer le chemin vers le fichier (p)\n- Ouvrir dans un éditeur de texte (t)\n- Lire (l)\n- Couper (X)\n- Renommer le fichier (r)\n- Supprimer le fichier (S)\n- Supprimer la liste (k)");
}
File::File(bool fileToBeSet) :NinjatodolaObject()
{
    setType("File");
    setMessage("\nMenu d'objet:\n- Exécuter (e)\n- Changer le chemin vers le fichier (p)\n- Ouvrir dans un éditeur de texte (t)\n- Lire (l)\n- Couper (X)\n- Renommer le fichier (r)\n- Supprimer le fichier (S)\n- Supprimer la liste (k)");
    if(fileToBeSet)
    {
        setPath();
    }
}

File::~File()
{

}

//methodes

void File::setPath() // define path
{
    std::string newPath;
    std::cout << "\nEntrer le chemin vers le fichier: " << std::endl;
    std::getline(std::cin, newPath); // Ask user for new path
    //verfiier si le chemin existe
    setPath(newPath);
}

void File::setPath(std::string path) // define path from string
{
    attrPath = path;
}

std::string File::getPath()
{
    return attrPath;
}

bool File::getExists()
{
    update();
    return attrExists;
}

NinjatodolaObject* File::action(std::string action)
{
NinjatodolaObject* toBeReturned(this); // the object return itself or another object
    if(action=="e")
    {
        executeFile();
    }

    else if(action=="p")
    {
        setPath();
    }

    else if(action=="t")
    {
        openFileInTextEditor();
    }

    else if(action=="l")
    {
        readFile();
    }

    else if(action=="r")
    {
        renameFile();
    }

    else if(action=="S")
    {
        deleteFile();
        attrMotherList->kill(attrPositionInMotherList); //kill self
        return attrMotherList;
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

void File::executeFile()
{
    std::string fileDir;
    std::vector<std::string> pathVec;
    pathVec = cutString(attrPath, "/", true);
    for(int i(0); i<pathVec.size() -1; i++)// get every part of the path but the last
    {
        fileDir += pathVec[i] + "/";
    }
    std::cout << "v\n" << std::endl;
    system(("cd " + fileDir + " && ./" + pathVec[pathVec.size() -1]).c_str());
}

void File::openFileInTextEditor()
{
    system(("vim " + attrPath).c_str());
}

void File::readFile()
{
    system(("less " + attrPath).c_str());
}

void File::renameFile()
{
    std::string newName;
    std::cout << "\nEntrer le nouveau nom du fichier: " << std::endl;
    std::getline(std::cin, newName); // Ask user for new path
    //verfiier si le chemin existe
    std::string newPath;
    std::vector<std::string> pathVec;
    pathVec = cutString(attrPath, "/");
    for(int i(0); i<pathVec.size(); i++)// get every part of the path but the last
    {
        newPath += pathVec[i] + "/";
    }
    newPath += newName;
    system(("mv " + attrPath + " " + newPath).c_str());
    attrPath = newPath;
}

void File::deleteFile()
{
    std::string answer;
    std::cout << "\nSupprimer le fichier? (Y/n): " << std::endl;
    std::getline(std::cin, answer); // Ask user for new path
    if(answer == "Y" || answer == "y" || answer == "yes")
    {
        system(("rm " + attrPath).c_str());
    }
}


std::vector<NinjatodolaObject*> File::getContent() const
{
    std::vector<NinjatodolaObject*> null;
    return null;
}

std::vector<NinjatodolaObject*> File::repr(std::vector<NinjatodolaObject*> vector)
{
    vector.push_back(this);
    return vector;
}

void File::update()
{
    setHightlight(false);
    if(!fileExists(attrPath))
    {
        attrSelfRepr = "Le fichier n'existe pas";
    }
    else{
    std::vector<std::string> pathVec;
    pathVec = cutString(attrPath, "/", true);
    attrSelfRepr = pathVec[pathVec.size()-1];
    }
}

std::string File::saveAsString()
{
    std::string saveString;
    saveString += std::to_string(attrIndent) + ";";
    saveString += attrType + ";";
    saveString += attrPath + ";";
    saveString += "\n";
    return saveString;
}

void File::loadFromString(std::vector<std::string> saveString)
{
    // saved string : indent;type;Path;
    //get attr
    int indent = stoi(cutString(saveString[0], ";")[0]);
    std::string type = cutString(saveString[0], ";")[1];
    std::string path = cutString(saveString[0], ";")[2];

    //change attr of self
    setIndent(indent);
    setType(type); //useless
    setPath(path);

}

void File::kill(int position)
{
    position = position; //useless
}