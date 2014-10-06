#include "Factory.h"
#include "MenuFunction.h"
#define METHOD(method) \
static_cast<action>(&Factory::method)

Factory::Factory()
    : Application("Factory Administration")
{
// register some methods as menu-functions
    functions.push_back(
        new MenuFunction( "add a supplier",
                          METHOD(addSupplier)) );
    functions.push_back(
        new MenuFunction( "add a machine",
                          METHOD(addMachine)) );
    functions.push_back(
        new MenuFunction( "report a problem",
                          METHOD(addProblem)) );
}

Factory::~Factory()
{
    //dtor
}
