#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "MenuFunction.h"

using namespace std;

class Application;
class MenuFunction;

class MenuHandler
{
    Application * const appl;
    vector<MenuFunction*> const & functions;
    public:
        MenuHandler(Application *app) : appl(app), functions(app->getFunctions()){}
        void showMenu() const;

};

#endif // MENUHANDLER_H
