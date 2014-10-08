#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H
#include "Application.h"
#include <iostream>
using namespace std;

typedef void (Application::* ApplFunction)();

class MenuFunction
{
private:
    const string description;
    //const ApplFunction function;
public:
    MenuFunction(const string& s) : description(s){}

    const string getDescription() const
    {
        return description;
    }

    //const ApplFunction getFunction() const
    //{
     //   return function;
    //}
};

#endif // MENUFUNCTION_H
