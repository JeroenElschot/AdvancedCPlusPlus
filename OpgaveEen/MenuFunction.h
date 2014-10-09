#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H
#include "Application.h"
#include "Factory.h"
#include <iostream>
using namespace std;

typedef void (Application::*ApplFunction)();

class MenuFunction
{
private:
    const string description;
    const ApplFunction myFunction;
public:
    MenuFunction(const string s, ApplFunction func) : description(s), myFunction(func){}

    const string getDescription() const
    {
        return description;
    }

    const ApplFunction getFunction()const
    {
        return myFunction;
    }


};

#endif // MENUFUNCTION_H
