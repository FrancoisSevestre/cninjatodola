#ifndef APPLICATION_H
#define APPLICATION_H

//custom libraries
#include "ninjatodolalist.hpp"

//standard libraries
#include <vector>
#include <string>

/**
 * Application is a list of commands.
 *
 * Can display them, run them one after the other like a script.
 * Can also display the result of its execution instead of its name.
 *
 */
class Application : public NinjatodolaList
{
    protected:

    public:

    //Constructors
    Application();
    Application(Application *listeToCopy);
    ~Application();

    //Methodes
    /**
    * not filled yet!
    *
    */
    NinjatodolaObject* action(std::string action);

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
        /**
     * Changes the TaskList attr, adds its content and recursively order them to do the same thing.
     */
    void loadFromString(std::vector<std::string> saveString);
    void kill(int position);

};

#endif // APPLICATION_H