#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "MenuFunction.h"

using namespace std;

class Factory;
class MenuFunction;

class MenuHandler
{
    Factory * const appl;
    vector<MenuFunction*> const & functions;
    public:
        MenuHandler(Factory *app) : appl(app), functions(app->getFunctions()){}
        void showStartMenu() const;
        void showMenu() const;

};

#endif // MENUHANDLER_H
