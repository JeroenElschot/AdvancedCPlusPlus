#include <iostream>
#include "Factory.h"
#include "MenuFunction.h"
#define METHOD(method) \

Factory::Factory(): Application("Application Menu")
{
    functions.push_back(new MenuFunction("1"));
}

void Factory::sayHello()
{
    cout << "hahah" << endl;
}


