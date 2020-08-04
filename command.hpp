#ifndef COMMAND_H
#define COMMAND_H

//custom libraries
#include "ninjatodolaobject.hpp"

//std libraries
#include <string>

/**
 * 
 * 
 * 
 */
class Command :public NinjatodolaObject
{
private:
    std::string attrLanguage;
public:
    Command();
    Command(bool commandToBeSet);
    // Command(Command *toCopy);
    ~Command();

    //Methodes
    /**
     * 
     */
    void setCommand(); // rewrite for command
    
    /**
     * 
     */
    void setLanguage(); // choose language
    void setLanguage(std::string language);

    /**
     * 
     */
    std::string getLanguage(); // get the current language

    /**
     * 
     */
    void executeSelf(); // execute the command

    /**
    * not filled yet!
    *
    */
    NinjatodolaObject* action(std::string action);

    /**
    * not filled yet!
    *
    */
    std::vector<NinjatodolaObject*> getContent() const; // should return nothing

   /**
   * Returns the ordonated representation
   * of the list and its content.
   * @param vec is a vector that will be append with pointers
   */
    std::vector<NinjatodolaObject*> repr(std::vector<NinjatodolaObject*> vec);

    //special
    /**
     * Updates the content of the list (usefull in certain cases: e.g. folders).
     */
    void update();

    std::string saveAsString();
        /**
     * Changes the TaskList attr, adds its content and recursively order them to do the same thing.
     */
    void loadFromString(std::vector<std::string> saveString);

    void kill(int position);


//reecrire la commande
//executer

};


#endif // COMMAND_H