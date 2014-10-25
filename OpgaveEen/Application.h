#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
using namespace std;

class MenuFunction;

class Application
{
protected:
    const string description;
    vector<MenuFunction *> functions;
public:
    Application(const string& s) : description(s) {}
    virtual ~Application()
    {
        //clean up references pointers?
    }

    const string& getDescription() const
    {
        return description;
    }

    const vector<MenuFunction*>& getFunctions() const
    {
        return functions;
    }
};

#endif // APPLICATION_H
