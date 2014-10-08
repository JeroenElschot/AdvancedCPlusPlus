#include <iostream>
#include "Factory.h"
#include "MenuFunction.h"

Factory::Factory(): Application("Application Menu")
{
    MenuFunction *mf = new MenuFunction("Function List");
    mf->setApplFunction(&Factory::sayHello);
    functions.push_back(mf);
}

void Factory::sayHello()
{
    cout << "Hallo, hoe is het" << endl;
}


