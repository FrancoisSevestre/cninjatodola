#ifndef DIRECTORY_H
#define DIRECTORY_H

//custom libraries
#include "ninjatodolalist.hpp"

//standard libraries
#include <vector>
#include <string>

class Directory : public NinjatodolaList
{
protected:
    std::string attrPath; //start and finishes with '/'
    bool attrExists;

public:
    //Constructors
    Directory(bool DirToBeSet=false);
    ~Directory();

    //Methodes
    void setPath(); // define path
    void setPath(std::string path); // define path from string
    std::string getPath();
    bool getExists();

    NinjatodolaObject* action(std::string action);
    void renameDir();
    bool deleteDir();
    std::vector<std::string> listDirs();
    std::vector<std::string> listFiles();
    void addDir();
    void addFile();
    void fillDirectory();

    // std::vector<NinjatodolaObject*> getContent() const;
    std::vector<NinjatodolaObject*> repr(std::vector<NinjatodolaObject*> vec);
    void update();
    std::string saveAsString();
    void loadFromString(std::vector<std::string> saveString);
    void kill(int position);
};

#endif // DIRECTORY_H