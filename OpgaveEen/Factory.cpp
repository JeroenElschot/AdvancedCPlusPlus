#include <iostream>
#include "Factory.h"

#define METHOD(method) \

static_cast<AdminFunction>(&Factory::method)

Factory::Factory(): Application("Application Menu")
{
    functions.push_back(new MenuFunction("say HELLO!",METHOD(sayHello)));
}

Factory::~Factory()
{
    //dtor
}
