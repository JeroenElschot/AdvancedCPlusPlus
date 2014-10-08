#include <iostream>
#include "MenuHandler.h"
#include "Factory.h"
#include "Application.h"

using namespace std;

int main()
{
    Factory *appl = new Factory();
    MenuHandler *handler = new MenuHandler(appl);
    handler->showStartMenu();

    delete handler;

    return 0;
}
