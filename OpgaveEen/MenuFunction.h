#ifndef MENUFUNCTION_H
#define MENUFUNCTION_H
#include "Application.h"
#include "Factory.h"
#include <iostream>
using namespace std;

typedef void (Factory::*ApplFunction)(void);

class MenuFunction
{
private:
    const string description;
    ApplFunction myFunction;
public:
    MenuFunction(const string& s, ApplFunction func) : description(s), myFunction(func){}

    const string getDescription() const
    {
        return description;
    }

    ApplFunction getFunction(){
        return myFunction;
    }


};

#endif // MENUFUNCTION_H
