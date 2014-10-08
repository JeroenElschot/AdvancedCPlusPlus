#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H

#include <string>       // voor: std::string

using std::string;

class Application; // to fix Application has not been delcared
typedef void (Application::* Function) ();

class MenuFunction
{
private:
    const string description;
    const Function function;
public:
    MenuFunction(const string& desc, const Function& func) :
        description(desc), function(func){}

    const string getDescription() const
    {
        return description;
    }
    const Function getFunction() const
    {
        return function;
    }
};

#endif // MENUFUNCTION_H
