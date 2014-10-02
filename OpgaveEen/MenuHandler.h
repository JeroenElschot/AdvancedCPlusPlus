#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <vector>
#include <iostream>
#include "MenuFunction.h"
#include "Application.h"

using namespace std;

class Application;
class MenuFunction;

class MenuHandler { // The generic handler
    Application * const appl;
    vector<MenuFunction*> const & functions;
public:
    MenuHandler(Application *ap): appl(ap), functions(ap->getFunctions())
    {

    }

    void showMenu() const;
};

#endif // MENUHANDLER_H

