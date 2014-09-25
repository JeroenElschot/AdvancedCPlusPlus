#include <iostream>

using namespace std;

int main()
{
    Application *appl = new Factory();
    MenuHandler *handler = new MenuHandler(appl);
    handler->showMenu();
    delete handler;
    delete appl;
}
