#include <iostream>
#include "MenuHandler.h"
#include "Factory.h"
#include "Application.h"

using namespace std;

int main()
{
    cout << "Starting program..." << endl;


    Factory *appl = new Factory();
    MenuHandler *handler = new MenuHandler(appl);
    handler->showMenu();

    delete handler;

    return 0;
}
