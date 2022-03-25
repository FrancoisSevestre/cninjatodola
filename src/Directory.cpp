#include "Directory.hpp"
#include "file.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "variousfunctions.hpp"

//Constructors
Directory::Directory(bool DirToBeSet)
{
    setType("Directory");
    setMessage("\nMenu d'objet:\n- Montrer/Cacher (!)\n- Mettre à jour le dossier (j)\n- Changer le chemin vers le dossier (p)\n- Créer un dossier (d)\n- Créer un fichier (f)\n- Couper (X)\n- Renommer le dossier (r)\n- Supprimer le dossier (S)\n- Supprimer de la liste (k)");
    if(DirToBeSet)
    {
        setPath();
        fillDirectory();
    }
}

Directory::~Directory()
{
    // add destruction of the content
    for(int i(0); i<getListSize() - 1; i++)
    {
    delContent(i);
    }
}

//Methodes
void Directory::setPath() // define path
{
    bool goodPath(false);
    while(!goodPath)
    {
        std::string newPath;
        std::cout << "\nEntrer le chemin vers le dossier: " << std::endl;
        std::getline(std::cin, newPath); // Ask user for new path
        //verfiier si le chemin existe
        if(newPath[0] == '/' && newPath[newPath.length()-1] == '/')
        {
        setPath(newPath);
        goodPath = true;
        }
        else
        {
            std::cout << "Chemin incorrect!\nLe chemin doit finir par commencer et finir par \'/\' !" << std::endl;
                  
        }
        
    }
}

void Directory::setPath(std::string path) // define path from string
{
    attrPath = path;
    fillDirectory();
}

std::string Directory::getPath()
{
    return attrPath;
}

bool Directory::getExists()
{
    update();
    return attrExists;
}


NinjatodolaObject* Directory::action(std::string action)
{
    NinjatodolaObject* toBeReturned(this); // the object return itself or another object
    if(action=="!")
    {
        switchShow();
    }

    else if(action=="j")
    {
        fillDirectory();
    }

    else if(action=="p")
    {
        setPath();
    }

    else if(action=="d")
    {
        addDir();
    }

    else if(action=="f")
    {
        addFile();
    }

    else if(action=="r")
    {
        renameDir();
    }

    else if(action=="S")
    {
        if(deleteDir())
        {
        attrMotherList->kill(attrPositionInMotherList); //kill self
        return attrMotherList;
        }
    }

    else if(action=="4")
    {
        setShow(false);
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
    
    else if(action == "6") // Move right
    {
    //   fillDirectory(); // Slows down the program
      setShow(true);
      // Verify that the object is not empty
      if(getListSize() > 0)
        {
          // Make the first item of the list the current object
          toBeReturned = attrContent[0];
        }
    }
    
    return toBeReturned;
}

void Directory::renameDir()
{
    std::string newName;
    std::cout << "\nEntrer le nouveau nom du dossier: " << std::endl;
    std::getline(std::cin, newName); // Ask user for new path
    //verfiier si le chemin existe
    std::string newPath;
    std::vector<std::string> pathVec;
    pathVec = cutString(attrPath, "/");
    for(int i(0); i<pathVec.size()-1; i++)// get every part of the path but the last
    {
        newPath += pathVec[i] + "/";
    }
    newPath += newName + "/";
    system(("mv " + attrPath + " " + newPath).c_str());
    attrPath = newPath;
}

bool Directory::deleteDir()
{
    std::string answer;
    std::cout << "\nSupprimer le dossier et tout son contenue? (Y/n): " << std::endl;
    std::getline(std::cin, answer); // Ask user for new path
    if(answer == "Y" || answer == "y" || answer == "yes")
    {
        system(("rm -rf " + attrPath).c_str());
        return true;
    }
    else
    {
        return false;
    }
    

}

std::vector<std::string> Directory::listDirs()
{
    std::vector<std::string> dirsList;
    dirsList = listDirectoriesInDirectory(attrPath);
    return dirsList;
}

std::vector<std::string> Directory::listFiles()
{
    std::vector<std::string> filesList;
    filesList = listFilesInDirectory(attrPath);
    return filesList;
}

void Directory::addDir()
{
    std::string newName;
    std::cout << "\nEntrer le nouveau nom du dossier: " << std::endl;
    std::getline(std::cin, newName); // Ask user for new path
    update();
    if(attrExists)
    {
        system(("mkdir " + attrPath + newName).c_str());
    }
    else{}
    fillDirectory();
}

void Directory::addFile()
{
    std::string newName;
    std::cout << "\nEntrer le nouveau nom du fichier: " << std::endl;
    std::getline(std::cin, newName); // Ask user for new path
    update();
    if(attrExists)
    {
        system(("touch " + attrPath + newName).c_str());
    }
    else{}
    fillDirectory();
}

std::vector<NinjatodolaObject*> Directory::repr(std::vector<NinjatodolaObject*> vec)
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

void Directory::fillDirectory()
{
    //erase all content
    attrContent.clear();
    //listDirs and create them
    std::vector<std::string> dirVec(listDirs());
    for(int i(0); i<dirVec.size(); i++)
    {
        Directory *newDirectory;
        newDirectory = new Directory();
        newDirectory->setPath(dirVec[i]);
        newDirectory->setShow(false);
        addContent(newDirectory);
    }
    //list files and create them
    std::vector<std::string> fileVec(listFiles());
    for(int i(0); i<fileVec.size(); i++)
    {
        File *newFile;
        newFile = new File();
        newFile->setPath(fileVec[i]);
        addContent(newFile);
    }
}


void Directory::update()
{
    setHightlight(false);
    
    //check existance
    attrExists = dirExists(attrPath);
    if (attrExists)
    {
    //define selfRepr
    std::vector<std::string> dirName = cutString(attrPath, "/");
    attrSelfRepr = dirName[dirName.size()-1];
    }
    else
    {
        attrSelfRepr = "Le dossier n'existe pas!";
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

std::string Directory::saveAsString()
{
    // saved string : indent;type;selfRepr;language;interpret;show
    std::string saveString;
    saveString += std::to_string(attrIndent) + ";";
    saveString += attrType + ";";
    saveString += attrPath + ";";
    saveString += "\n";

    //no content needs to be saved

    return saveString;
}

void Directory::loadFromString(std::vector<std::string> saveString)
{
    //get attr
    int indent = stoi(cutString(saveString[0], ";")[0]);
    std::string type = cutString(saveString[0], ";")[1];
    std::string path = cutString(saveString[0], ";")[2];

    //change attr of self
    setIndent(indent);
    setType(type); //useless
    setPath(path);
    setShow(false);
    fillDirectory();
}

void Directory::kill(int position)
{
    delContent(position); // not sure...
}
