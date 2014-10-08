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
    MenuFunction(const string& s) : description(s){}

    const string getDescription() const
    {
        return description;
    }

    void setApplFunction(ApplFunction func){
        myFunction = func;
    }

    ApplFunction getFunction(){
        return myFunction;
    }


};

#endif // MENUFUNCTION_H
