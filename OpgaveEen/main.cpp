#include <iostream>
#include "MenuHandler.h"

using namespace std;

int main()
{
    cout << "Starting program..." << endl;

    MenuHandler *handler = new MenuHandler();
    handler->showMenu();

    delete handler;

    return 0;
}
