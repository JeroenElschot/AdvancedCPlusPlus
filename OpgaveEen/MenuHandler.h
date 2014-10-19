#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include <map>

#include "MenuFunction.h"

class Application;
class MenuFunction;


class MenuHandler
{
    Application * const appl;
    vector<MenuFunction*> const & functions; // aanbod van applicatie
    map<char,MenuHandler*> *menus;
    map<int, char> *keys; // houd de bindings bij voor de functies en keys

    public:

        MenuHandler(Application *app) : appl(app), functions(app->getFunctions())
        {
            keys = new map<int, char>();
            menus = new map<char,MenuHandler*>();
        }
        void showStartMenu() const;
        void showMenu() const;
        void BindFunctions() const;
        void unBind() const;
        void gosub(int);
        void makeSub() const;

};

#endif // MENUHANDLER_H
