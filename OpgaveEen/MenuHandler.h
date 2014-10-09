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
    vector<MenuFunction*> const & functions; // aanbod van applicatie
    //vector< map<char,MenuFunction*> *>         menus;
    public:
        MenuHandler(Application *app) : appl(app), functions(app->getFunctions()){}
        void showStartMenu() const;
        void showMenu() const;
        void bind();
        void unbind();
        void gosub(int);

};

#endif // MENUHANDLER_H
