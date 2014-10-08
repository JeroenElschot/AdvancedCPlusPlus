#include <iostream>
#include "Factory.h"
#include "MenuFunction.h"
#define METHOD(method)

//static_cast<TEST>(&Factory::method);

Factory::Factory(): Application("Application Menu")
{
    functions.push_back(new MenuFunction("1",METHOD(sayHello)));
}


