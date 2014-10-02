#include "Factory.h"
#define METHOD(method) \
static_cast<AdminFunction>(&Factory::method)

Factory::Factory()
    : Application("Factory Administration")
{
// register some methods as menu-functions
    menufunctions.push_back(
        new MenuFunction( "add a supplier",
                          METHOD(addSupplier)) );
    menufunctions.push_back(
        new MenuFunction( "add a machine",
                          METHOD(addMachine)) );
    menufunctions.push_back(
        new MenuFunction( "report a problem",
                          METHOD(addProblem)) );
}

Factory::~Factory()
{
    //dtor
}
