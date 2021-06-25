#ifndef FILE_H
#define FILE_H

//custom libraries
#include "ninjatodolaobject.hpp"

//std libraries
#include <string>

class File :public NinjatodolaObject
{
protected:
    std::string attrPath;
    bool attrExists;

public:
    File();
    File(bool fileToBeSet);
    ~File();

    //methodes

    void setPath(); // define path
    void setPath(std::string path); // define path from string
    std::string getPath();

    bool getExists();

    NinjatodolaObject* action(std::string action);
    void executeFile();
    void openFileInTextEditor();
    void readFile();
    void renameFile();
    void deleteFile();



    std::vector<NinjatodolaObject*> getContent() const;
    std::vector<NinjatodolaObject*> repr(std::vector<NinjatodolaObject*> vector);
    void update();
    std::string saveAsString();
    void loadFromString(std::vector<std::string> saveString);
    void kill(int position);
};

#endif // FILE_H
