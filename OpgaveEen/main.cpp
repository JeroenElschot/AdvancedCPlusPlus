#include <iostream>
#include "MenuHandler.h"
#include "Application.h"

using namespace std;

int main()
{
    cout << "Starting program..." << endl;

    Application *appl = new Application("test");
    MenuHandler *handler = new MenuHandler(appl);
    handler->showMenu();

    delete handler;

    return 0;
}
